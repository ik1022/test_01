# Embedded Cpp with Unitest (CppUTest)

## preparation

### docker login in host pc
```sh
docker login https://git.etc-lab.kr
id:
pass: 
```
=== 
## Build

### target build
```sh
rm -Rf .build
cmake -S. -B.build -GNinja
cmake --build .build --clean-first
arm-none-eabi-objcopy -Oihex .build/mcu.elf .build/mcu.hex
```

### unit test
```sh
rm -Rf .build_test
cmake -S. -B.build_test -GNinja -DBUILD_FOR_UNIT_TESTS=ON
cmake --build .build_test --clean-first
ctest  --test-dir .build_test/
.build_test/tests/UnitTests -v
```

=== 
## Debug with pyocd
```sh
pyocd erase --pack ABOV.A31G1xx_Series.2.5.0.pack -uremote:host.docker.internal:5555 --mass -ta31g123
pyocd flash --pack ABOV.A31G1xx_Series.2.5.0.pack -uremote:host.docker.internal:5555 -ta31g123 .build/mcu.hex
```
