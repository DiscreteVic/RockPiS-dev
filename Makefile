
GCC=aarch64-none-elf

APP=app

all: clean build-c pack upload

build-c: 
	@ mkdir -p build/
	@ $(GCC)-gcc -mtune=cortex-a35 -S main.c -o build/main.asm
	@ $(GCC)-as -o build/main.o build/main.asm
	@ $(GCC)-ld -o build/main build/main.o
	@ $(GCC)-objcopy -S -O binary build/main build/app.bin

build-asm: 
	@ mkdir -p build/
	@ $(GCC)-as -o build/$(APP).o $(APP).asm
	@ $(GCC)-ld -o build/$(APP) build/$(APP).o
	@ $(GCC)-objcopy -S -O binary build/$(APP) build/$(APP).bin

pack:
	@ python3 pack.py

upload:
	@ sudo timeout 2 rkdeveloptool db build/loader.bin

clean:
	@ rm -rf build/

