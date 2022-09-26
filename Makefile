
GCC=aarch64-none-elf

APP=app

all: clean build pack upload

build: 
	@ mkdir -p build/
	@ $(GCC)-gcc -mtune=cortex-a35 -ffreestanding -c -o build/main.o -Iinclude main.c 
	@ $(GCC)-gcc -mtune=cortex-a35 -ffreestanding -c -o build/rk3308.o include/rk3308.c
	@ $(GCC)-gcc --entry=main -ffreestanding -nostdlib build/main.o build/rk3308.o -o build/main
	@ $(GCC)-objcopy -S -O binary build/main build/app.bin


pack:
	@ python3 pack.py

upload:
	@ sudo timeout 2 rkdeveloptool db build/loader.bin

clean:
	@ rm -rf build/

