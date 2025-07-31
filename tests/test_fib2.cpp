#include "CppUTest/TestHarness.h"

#include <fibonacci.hpp>

TEST_GROUP(FooTestGroup){void setup(){} void teardonw(){}};

TEST(FooTestGroup, Foo01)
{
    CHECK_EQUAL(fibonacci(10), 55);
    CHECK(fibonacci(10) == 55);
    CHECK_TEXT(fibonacci(10) == 55, "finonacci 10 = 55");
    CHECK_FALSE(fibonacci(10) == 56);
}

TEST(FooTestGroup, Foo02)
{
    CHECK_EQUAL(fibonacci(1), 1);
    CHECK(fibonacci(1) == 1);
    CHECK_TEXT(fibonacci(1) == 1, "finonacci 1 = 1");
    CHECK_FALSE(fibonacci(1) == 2);
}
