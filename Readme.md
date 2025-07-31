# Embedded Cpp test
### docker login
```sh
# in host pc
docker login https://git.etc-lab.kr
id:
pass: 
```

### old in container

``` sh
arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -I"..\Device_A31G12x" -std=gnu11 -MMD -MP -MF"App/main.d" -MT"App/main.o" -c -o "App/main.o" "../App/main.c"

arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -I"..Device_A31G12x" -std=gnu11 -MMD -MP -c -o "A31G_startup.o" "../Device_A31G12x/A31G_startup.c"


arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -T "..\Device_A31G12x\mem_4k_32k.ld" -T "..\Device_A31G12x\sections.ld" -T "..\Device_A31G12x\libs.ld" -Xlinker --gc-sections -Xlinker --print-gc-sections -s -Wl,-Map,"mm32g0001_test03.map" --specs=nano.specs --specs=nosys.specs -o "mm32g0001_test03.elf"  ./main.o  ./A31G_startup.o

arm-none-eabi-objcopy -O ihex mm32g0001_test03.elf mm32g0001_test03.hex
```



### new in container

```sh

cmake -S. -B.build -GNinja
cmake --build .build --clean-first
ctest  --test-dir .build/
.build/tests/UnitTests -v

arm-none-eabi-objcopy -Oihex .build/mcu.elf .build/mcu.hex

pyocd erase --pack ABOV.A31G1xx_Series.2.5.0.pack -uremote:host.docker.internal:5555 --mass -ta31g123

pyocd flash --pack ABOV.A31G1xx_Series.2.5.0.pack -uremote:host.docker.internal:5555 -ta31g123 .build/mcu.hex
```
