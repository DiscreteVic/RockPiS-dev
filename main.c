#include <stdio.h>
#include "rk3308.h"


void main(){
    initRK3308();
    
    // SET GPIO DIRECTION GPIO0_A and GPIO0_B to output and GPIO0_C and GPIO0_D left as input
    setGPIO_DDR(GPIO0, 0xFFFF);

    while(1){
        // SET GPIO VALUE GPIO_B3 and GPIO_A6 to 1
        setGPIO_DR(GPIO0, 0x0820);
        // WAIT 1 second
        wait_ms(1000);
        // SET GPIO VALUE GPIO_B3 to 0 and GPIO_A6 to 1
        setGPIO_DR(GPIO0, 0x0020);
        // WAIT 1 second
        wait_ms(1000);
    }
}