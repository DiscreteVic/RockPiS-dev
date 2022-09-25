#include <stdio.h>

__asm__(".word 0x33334b52");

void main() asm("_start");

void main(){
    __asm__(
        "mrs x9, mpidr_el1\n\t"
        "tst x9, 0b11\n\t"
        "b.eq . + 0x0c\n\t"
        "wfe\n\t"
        "b.al . - 0x04\n\t"
        "movz x9, :abs_g1:0xff220000\n\t"
        "mov w10, 0x20\n\t"
        "str w10, [x9, 0x0004]\n\t"
        "str w10, [x9, 0x0000]\n\t"
        "b.al .\n\t"
    );
}