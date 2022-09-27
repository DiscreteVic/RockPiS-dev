#ifndef RK3308
#define RK3308

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;

typedef enum{
    false = 0,
    true = 1
} bool;

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

#endif