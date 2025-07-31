cmake_minimum_required(VERSION 3.16)
project(a31g123_mcu_project C ASM)

# if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#  message(FATAL_ERROR "Please specify toolchain file via -DCMAKE_TOOLCHAIN_FILE")
# endif()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

#set(CMAKE_EXE_LINKER_FLAGS "-T${CMAKE_SOURCE_DIR}/linker/A31G123_flash.ld -nostartfiles")
set(CMAKE_C_FLAGS "-mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -std=gnu11 " CACHE STRING "" FORCE)

set(CMAKE_CXX_FLAGS "-mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -std=gnu11 " CACHE STRING "" FORCE)

set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m0 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g -Xlinker --gc-sections -s --specs=nano.specs --specs=nosys.specs -T ${CMAKE_SOURCE_DIR}/Device_A31G12x/mem_4k_32k.ld -T ${CMAKE_SOURCE_DIR}/Device_A31G12x/sections.ld")


add_executable(mcu.elf
    Device_A31G12x/A31G_startup.c
    App/main.c
)

target_include_directories(mcu.elf PRIVATE
    ${CMAKE_SOURCE_DIR}/App
	${CMAKE_SOURCE_DIR}/Device_A31G12x
)

# target_compile_options(mcu.elf PRIVATE
#    ${CMAKE_C_FLAGS}
# )

# enable_testing()
# add_subdirectory(tests)
# add_test(NAME LedTest COMMAND unit_tests)
