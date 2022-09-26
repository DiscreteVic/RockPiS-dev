#include <stdio.h>

__asm__(".word 0x33334b52");

void main() asm("_start");

void main(){

    // CHECKING MPIDR_EL1 NEED to be equal than 0
    //__asm__(
    //    "mrs x9, mpidr_el1\n\t"
    //    "tst x9, 0b11\n\t"
    //    "b.eq . + 0x0c\n\t"
    //    "wfe\n\t"
    //    "b.al . - 0x04\n\t"
    //);
    
    *((unsigned int*)0xff220004) = (char *)0x20;
    *((unsigned int*)0xff220000) = (char *)0x20;
    

    while(1){}
}