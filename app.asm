.cpu cortex-a35
.global _start


ROCKPIS_BLUE_LED = 0x20

GPIO0_BASEADDR = 0xff220000

GPIO_SWPORTA_DR = 0x0000
GPIO_SWPORTA_DDR = 0x0004

.section .text
.word 0x33334b52

_start:

        mrs x9, mpidr_el1
        tst x9, 0b11
        b.eq . + 0x0c
        wfe
        b.al . - 0x04
        movz x9, :abs_g1:GPIO0_BASEADDR
        mov w10, ROCKPIS_BLUE_LED
        str w10, [x9, GPIO_SWPORTA_DDR]
        str w10, [x9, GPIO_SWPORTA_DR]
        b.al .