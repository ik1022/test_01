set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PREFIX arm-none-eabi-)

set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}gcc)

# -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -Xlinker --gc-sections -Xlinker --print-gc-sections -s -Wl,-Map,"mm32g0001_test03.map" --specs=nano.specs --specs=nosys.specs
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m0 -mthumb -Os -g --specs=nano.specs --specs=nosys.specs -T ${CMAKE_SOURCE_DIR}/Device_A31G12x/mem_4k_32k.ld -T ${CMAKE_SOURCE_DIR}/Device_A31G12x/sections.ld")


# -mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -std=gnu11 -MMD -MP
set(CMAKE_C_FLAGS "-mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -std=gnu11 " CACHE STRING "" FORCE)
set(CMAKE_ASM_FLAGS "-mcpu=cortex-m0 -mthumb" CACHE STRING "" FORCE)


# objcopy
# arm-none-eabi-objcopy -O ihex mm32g0001_test03.elf mm32g0001_test03.hex
