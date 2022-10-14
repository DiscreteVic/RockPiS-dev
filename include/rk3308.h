#ifndef RK3308
#define RK3308

#include "common.h"

#define CRU_BASE_ADDR       0xFF500000U

#define CRU_DPLL_CON0       CRU_BASE_ADDR + 0x20U      
#define CRU_DPLL_CON1       CRU_BASE_ADDR + 0x24U
#define CRU_CLKGATE_CON1    CRU_BASE_ADDR + 0x304U
#define CRU_CLKGATE_CON2    CRU_BASE_ADDR + 0x308U
#define CRU_CLKSEL_CON10    CRU_BASE_ADDR + 0x128U
#define CRU_CLKSEL_CON11    CRU_BASE_ADDR + 0x12CU
#define CRU_CLKSEL_CON12    CRU_BASE_ADDR + 0x130U
#define CRU_CLKSEL_CON13    CRU_BASE_ADDR + 0x134U
#define CRU_CLKSEL_CON14    CRU_BASE_ADDR + 0x138U
#define CRU_CLKSEL_CON15    CRU_BASE_ADDR + 0x13CU

#define GRF_BASE_ADDR       0xFF000000U

#define GRF_GPIO1D_I0MUX    GRF_BASE_ADDR + 0x0038U
#define GRF_GPIO2A_I0MUX    GRF_BASE_ADDR + 0x0040U

#define GPIO_BASE_ADDR      0xFF220000U
#define GPIO_BASE_OFFSET    0x00010000U

#define GPIO_SWPORTA_DR     0x0000U
#define GPIO_SWPORTA_DDR    0x0004U

#define GPIO(num)           GPIO_BASE_ADDR + (GPIO_BASE_OFFSET * num)

#define GPIO_DR(num)        GPIO(num) + GPIO_SWPORTA_DR
#define GPIO_DDR(num)       GPIO(num) + GPIO_SWPORTA_DDR


#define UART0_BASE_ADDR     0xFF0A0000U
#define UART1_BASE_ADDR     0xFF0B0000U
#define UART2_BASE_ADDR     0xFF0C0000U
#define UART3_BASE_ADDR     0xFF0D0000U
#define UART4_BASE_ADDR     0xFF0E0000U

#define UART0_RBR           UART0_BASE_ADDR + 0x0000U
#define UART0_THR           UART0_BASE_ADDR + 0x0000U
#define UART0_DLL           UART0_BASE_ADDR + 0x0000U
#define UART0_DLH           UART0_BASE_ADDR + 0x0004U
#define UART0_IER           UART0_BASE_ADDR + 0x0004U
#define UART0_IIR           UART0_BASE_ADDR + 0x0008U

#define UART0_LCR           UART0_BASE_ADDR + 0x000CU

#define UART0_MCR           UART0_BASE_ADDR + 0x0010U

#define UART0_USR           UART0_BASE_ADDR + 0x0006U   //RO



#define UART1_RBR           UART1_BASE_ADDR + 0x0000U
#define UART1_THR           UART1_BASE_ADDR + 0x0000U
#define UART1_DLL           UART1_BASE_ADDR + 0x0000U
#define UART1_DLH           UART1_BASE_ADDR + 0x0004U
#define UART1_IER           UART1_BASE_ADDR + 0x0004U
#define UART1_IIR           UART1_BASE_ADDR + 0x0008U

#define UART1_LCR           UART1_BASE_ADDR + 0x000CU

#define UART1_MCR           UART1_BASE_ADDR + 0x0010U

#define UART1_USR           UART1_BASE_ADDR + 0x0006U   //RO

#define getIPBaseAddr(ip,num) ip##_BASE_ADDR + (ip##_BASE_OFFSET * num)



typedef enum{
    GPIO0 = 0,
    GPIO1 = 1,
    GPIO2 = 2,
    GPIO3 = 3,
    GPIO4 = 4
} gpio_t;

typedef enum{
    A0 = 0x00,
    A1 = 0x01,
    A2 = 0x02,
    A3 = 0x03,
    A4 = 0x04,
    A5 = 0x05,
    A6 = 0x06,
    A7 = 0x07,
    B0 = 0x08,
    B1 = 0x09,
    B2 = 0x0A,
    B3 = 0x0B,
    B4 = 0x0C,
    B5 = 0x0D,
    B6 = 0x0E,
    B7 = 0x0F,
    C0 = 0x10,
    C1 = 0x11,
    C2 = 0x12,
    C3 = 0x13,
    C4 = 0x14,
    C5 = 0x15,
    C6 = 0x16,
    C7 = 0x17,
    D0 = 0x18,
    D1 = 0x19,
    D2 = 0x1A,
    D3 = 0x1B,
    D4 = 0x1C,
    D5 = 0x1D,
    D6 = 0x1E,
    D7 = 0x1F
} gpioPin_t;

__asm__(".word 0x33334b52");

void wait_ms(uint32_t milliseconds);

int initRK3308();

void setGPIO_DDR(gpio_t gpio, uint32_t dirReg);

void setGPIO_DR(gpio_t gpio, uint32_t dataReg);

uint32_t getGPIO_DR(gpio_t gpio);

void setGPIO_Pin(gpio_t gpio, gpioPin_t pin, bool pinValue);

bool getGPIO_Pin(gpio_t gpio, gpioPin_t pin);

void initUART();

#endif