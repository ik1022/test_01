
rm -Rf .build
cmake -S. -B.build -GNinja
cmake --build .build --clean-first
arm-none-eabi-objcopy -Oihex .build/mcu.elf .build/mcu.hex