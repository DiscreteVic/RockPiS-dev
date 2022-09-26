#ifndef RK3308
#define RK3308

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;

#define GPIO_BASE_ADDR     0xFF220000U
#define GPIO_BASE_OFFSET   0x00010000U

#define GPIO_SWPORTA_DR     0x0000U
#define GPIO_SWPORTA_DDR    0x0004U

#define getIPBaseAddr(ip,num) ip##_BASE_ADDR + (ip##_BASE_OFFSET * num)

typedef enum{
    GPIO0 = 0,
    GPIO1 = 1,
    GPIO2 = 2,
    GPIO3 = 3,
    GPIO4 = 4
} gpio_t;

__asm__(".word 0x33334b52");

void wait_ms(uint32_t milliseconds);

int initRK3308();

void setGPIO_DDR(gpio_t gpio, uint32_t dirReg);

void setGPIO_DR(gpio_t gpio, uint32_t dataReg);

#endif