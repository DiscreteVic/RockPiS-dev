#include "rk3308.h"



void writeWordRegister(uint32_t address, uint32_t value){
    *((uint32_t *)address) = (uint32_t)value;
}

void writeUpHalfWordRegister(uint32_t address, uint16_t value){
    *((uint32_t *)address) = ((*((uint32_t *)address) & 0x0000FFFF) | ((uint32_t)value) << 32);
}

void writeLowHalfWordRegister(uint32_t address, uint16_t value){
    *((uint32_t *)address) = ((*((uint32_t *)address) & 0xFFFF0000) | ((uint32_t)value));
}

uint32_t readWordRegister(uint32_t address){
    return *((uint32_t *)address);
}


void writeByteRegister(uint32_t address, uint8_t byte, uint8_t value){
    uint32_t tmpReg, resReg;

    tmpReg = readWordRegister(address);

    resReg = ((tmpReg & ~(0x000000FF << (byte * 8))) | (value << (byte * 8)));

    writeWordRegister(address, resReg);
}

uint8_t readByteRegister(uint32_t address, uint8_t byte){
    uint32_t tmpReg;

    tmpReg = readWordRegister(address);

    return (tmpReg >> (byte * 8)) && 0x000000FF;
}

void writeBitRegister(uint32_t address, uint8_t bit, bool value){
    uint32_t tmpReg, resReg;

    tmpReg = readWordRegister(address);

    if(value == 1) resReg = tmpReg | (0x00000001 << bit);
    else  resReg = tmpReg & ~(0x00000001 << bit);

    writeWordRegister(address, resReg);
}

bool readBitRegister(uint32_t address,uint8_t bit){
    uint32_t tmpReg;

    tmpReg = readWordRegister(address);

    return (tmpReg >> bit) & 0xFFFE;
}

void writeMaskedRegister(uint32_t address, uint16_t value){

    //Mask upper bytes register
    writeUpHalfWordRegister(address, 0xFFFF);
    //Write register
    writeLowHalfWordRegister(address, value);
    //Unmasked 
    writeUpHalfWordRegister(address, 0x0000);
}

void wait_ms(uint32_t milliseconds){
    uint32_t i, j;
    //AVOID TO USE MULTIPLICATION DUE TO RESOURCES CONSUPTION (TO BE CONFIRMED)
    for(j = 0; j < milliseconds; j++){
        //CYCLES VAULE OBTAINED EXPERIMENTALY
        for(i = 0; i < 1413; i++);
    }
}

// PUBLIC FUNCTIONS

int initRK3308(){

    // CHECKING MPIDR_EL1 NEED to be equal than 0
    //__asm__(
    //    "mrs x9, mpidr_el1\n\t"
    //    "tst x9, 0b11\n\t"
    //    "b.eq . + 0x0c\n\t"
    //    "wfe\n\t"
    //    "b.al . - 0x04\n\t"
    //);
    
    return 0;
}

void setGPIO_DDR(gpio_t gpio, uint32_t dirReg){
    writeWordRegister(getIPBaseAddr(GPIO,gpio) + GPIO_SWPORTA_DDR, dirReg);
}

void setGPIO_DR(gpio_t gpio, uint32_t dataReg){
    writeWordRegister(getIPBaseAddr(GPIO,gpio) + GPIO_SWPORTA_DR, dataReg);
}

uint32_t getGPIO_DR(gpio_t gpio){  //NOT TESTED
    return readWordRegister(getIPBaseAddr(GPIO,gpio) + GPIO_SWPORTA_DR);
}

void setGPIO_Pin(gpio_t gpio, gpioPin_t pin, bool pinValue){
    uint32_t gpioDR;

    gpioDR = getGPIO_DR(gpio);

    if(pinValue == 1) gpioDR = gpioDR | (uint32_t)(1U << pin);
    else gpioDR = gpioDR & ~((uint32_t)(1U << pin));

    setGPIO_DR(gpio, gpioDR);
}

bool getGPIO_Pin(gpio_t gpio, gpioPin_t pin){ //NOT TESTED
    uint32_t gpioDR;
    bool pinValue;

    gpioDR = getGPIO_DR(gpio);

    pinValue = (bool)((gpioDR >> pin) & 0x0001);

    return pinValue;
}

void initUART(){

    // CONFIGURE FOUTPOSTDIV 
    // RK3308 TRM-Part1 2.5.1
    // FBDIV = 500, POSTDIV1 = 1, BYPASS = 0 => CRU_DPLL_CON0 = 0x----11F4
    writeMaskedRegister(CRU_DPLL_CON0, 0x11F4);

    // DSMPD = 1, POSTDIV2 = 1, REFDIV = 1 => CRU_DPLL_CON1 = 0x----1021
    writeMaskedRegister(CRU_DPLL_CON1, 0x1021);


    // CONFIGURE CGU

    //Configure clk selectors and divs S10_13 S10_0 S11_14 S11_0 

    //Set de gates => G1_9 G1_10 G1_12

    writeMaskedRegister(CRU_CLKGATE_CON1, 0x1600);

    //D1



    // CONFIGURE GRF

    writeByteRegister(GRF_GPIO2A_I0MUX, 0, 0x05);


    //SET LCR[7] to select DLL,DLH
    writeBitRegister(UART0_LCR, 7, 1);
    
    //SET LCR[1:0] to select data width
    writeBitRegister(UART0_LCR, 0, 1);
    writeBitRegister(UART0_LCR, 1, 1);

    //SET DLL,DLH to decide baud rate
    writeByteRegister(UART0_DLL, 0, 0x01);
    writeByteRegister(UART0_DLH, 0, 0x00);

    //Write data to THR Set MCR to start the transfer
    writeByteRegister(UART0_THR, 0, 0x5A);
    writeBitRegister(UART0_MCR, 2, 1);

    //Wait transfer end




}