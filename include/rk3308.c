#include "rk3308.h"

void writeWordRegister(uint32_t address, uint32_t value){
    *((uint32_t *)address) = (uint32_t)value;
}

uint32_t readWordRegister(uint32_t address){
    return *((uint32_t *)address);
}

void wait_ms(uint32_t milliseconds){
    uint32_t i, j;
    //AVOID TO USE MULTIPLICATION DUE TO RESOURCES CONSUPTION (TO BE CONFIRMED)
    for(j = 0; j < milliseconds; j++){
        //CYCLES VAULE OBTAINED EXPERIMENTALY
        for(i = 0; i < 1413; i++);
    }
}


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