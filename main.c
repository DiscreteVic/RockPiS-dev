#include <stdio.h>
#include "rk3308.h"
#include "mdp.h"

struct mdpPort mdpPortA, mdpPortB;


void main(){
    initRK3308();
    
    // SET GPIO DIRECTION GPIO0_A and GPIO0_B to output and GPIO0_C and GPIO0_D left as input
    setGPIO_DDR(GPIO0, 0xFFFF);
    setGPIO_DDR(GPIO2, 0xFFFF);
  //  setGPIO_Pin(GPIO0, A6, true);


  //  initUART();
    mdpCreatePort(GPIO_DR(2), A4, MS_CYCLES, 1, &mdpPortA);
    mdpCreatePort(GPIO_DR(0), B4, MS_CYCLES, 1, &mdpPortB);

    mdpInitPort(mdpPortA);

    while(1){
        
        mdpUARTDisplayValue(mdpPortA, 0x5A);

    }
}