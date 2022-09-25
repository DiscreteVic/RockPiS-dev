
GCC=aarch64-none-elf

APP=app

all: clean build pack upload

build: 
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
