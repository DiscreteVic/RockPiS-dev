
GCC=aarch64-none-elf

APP=app

all: clean build pack upload

build: 
	@ mkdir -p build/
	@ $(GCC)-gcc -mtune=cortex-a35 -ffreestanding -c -o build/main.o -Iinclude main.c 
	@ $(GCC)-gcc -mtune=cortex-a35 -ffreestanding -c -o build/rk3308.o include/rk3308.c
	@ $(GCC)-gcc -mtune=cortex-a35 -ffreestanding -c -o build/mdp.o include/mdp.c
	@ $(GCC)-gcc --entry=main -ffreestanding -nostdlib build/main.o build/rk3308.o build/mdp.o -o build/main
	@ $(GCC)-objcopy -S -O binary build/main build/app.bin


pack:
	@ python3 pack.py

newpack:
	@ python3 newpack.py rk3308_ddr_589MHz_uart1_m0_v1.26.bin build/app.bin build/loader.bin


upload:
	@ sudo timeout 2 rkdeveloptool db build/loader.bin

clean:
	@ rm -rf build/

