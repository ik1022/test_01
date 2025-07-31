#include "CppUTest/TestHarness.h"

#include <fibonacci.hpp>


TEST_GROUP(BarTestGroup){void setup(){} void teardonw(){}};

TEST(BarTestGroup, Bar01)
{
    CHECK_EQUAL(fibonacci(2), 1);
    CHECK(fibonacci(2) == 1);
    CHECK_TEXT(fibonacci(2) == 1, "finonacci 2 = 1");
    CHECK_FALSE(fibonacci(2) == 2);
}

TEST(BarTestGroup, Bar02)
{
    CHECK_EQUAL(fibonacci(3), 2);
    CHECK(fibonacci(3) == 2);
    CHECK_TEXT(fibonacci(3) == 2, "finonacci 3 = 2");
    CHECK_FALSE(fibonacci(3) == 4);
}
