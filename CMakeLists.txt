cmake_minimum_required(VERSION 3.16)
project(a31g123_mcu_project C ASM)

# if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#  message(FATAL_ERROR "Please specify toolchain file via -DCMAKE_TOOLCHAIN_FILE")
# endif()

if(BUILD_FOR_UNIT_TESTS)
  set(UNIT_TEST TRUE)
else()
  set(MCU_BUILD TRUE)
endif()

if(MCU_BUILD)
    message("MCU build")

    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_C_COMPILER arm-none-eabi-gcc)
    set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
    set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

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

endif()


if(UNIT_TEST)
    message("UNIT_TEST build")
    # CppUTest integration
    set(CPPUTEST_HOME ${CMAKE_SOURCE_DIR}/cpputest_build CACHE PATH "Path to CppUTest build directory")
    add_subdirectory(tests)
    enable_testing()
    add_test(NAME RunUnitTests COMMAND UnitTests)
endif()
