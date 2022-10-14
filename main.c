#include <stdio.h>
#include "rk3308.h"
#include "mdp.h"

struct mdpPort mdpPortA;


void main(){
    initRK3308();
    
    // SET GPIO DIRECTION GPIO0_A and GPIO0_B to output and GPIO0_C and GPIO0_D left as input
    setGPIO_DDR(GPIO2, 0xFFFF);
  //  setGPIO_Pin(GPIO0, A6, true);


  //  initUART();
    mdpCreatePort(GPIO_DR(2), A4, &mdpPortA);

    while(1){
        // SET GPIO VALUE GPIO_B3 and GPIO_A6 to 1
        mdpSetPort(mdpPortA, 1);
        //setGPIO_Pin(GPIO2,A4, 1);
        // WAIT 1 second
        wait_ms(500);
        // SET GPIO VALUE GPIO_B3 to 0 and GPIO_A6 to 1
        mdpSetPort(mdpPortA, 0);
        //setGPIO_Pin(GPIO2,A4, 0);
        // WAIT 1 second
        wait_ms(500);
    }
}