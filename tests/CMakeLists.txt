cmake_minimum_required(VERSION 3.16)

project(UnitTests CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

# Clear embedded-specific flags for host compilation
set(CMAKE_C_FLAGS "" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "" CACHE STRING "" FORCE)

include_directories(
    /home/ubuntu/workspace/cpputest/include
    ../App
)
link_directories(
    /home/ubuntu/workspace/cpputest_build/src/CppUTest
    /home/ubuntu/workspace/cpputest_build/src/CppUTestExt
)


add_executable(UnitTests
    TestApp.cpp
    test_fib.cpp
    test_fib2.cpp
    test_value.cpp
    ../App/fibonacci.cpp
)

target_link_libraries(UnitTests
    CppUTest
    CppUTestExt
)

add_test(NAME RunUnitTests COMMAND UnitTests)
