#!/bin/sh

rm -Rf .build
cmake -S. -B.build -GNinja
cmake --build .build --clean-first

mkdir .bin
arm-none-eabi-objcopy -Oihex .build/mcu.elf .bin/mcu.hex

arm-none-eabi-size --format=berkeley .build/mcu.elf

exit 0