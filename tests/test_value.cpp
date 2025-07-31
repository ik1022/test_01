#include "CppUTest/TestHarness.h"

#include "value.hpp"

TEST_GROUP(TestGroup_value)
{
    void setup() {};
    void teardonw() {};
};

TEST(TestGroup_value, value_01)
{
    ClassValue v1 = ClassValue{1000, 1, 1000};

    CHECK_EQUAL(1, 1);

    v1.setValue(1);
    CHECK_EQUAL(v1.getValue(), 1);

    v1.setValue(0);
    CHECK_EQUAL(v1.getValue(), 1);

    v1.setValue(1000);
    CHECK_EQUAL(v1.getValue(), 1000);

    v1.setValue(1001);
    CHECK_EQUAL(v1.getValue(), 1000);

    v1.setValue(-1);
    CHECK_EQUAL(v1.getValue(), 1);


    // CHECK(fibonacci(2) == 1);
    // CHECK_TEXT(fibonacci(2) == 1, "finonacci 2 = 1");
    // CHECK_FALSE(fibonacci(2) == 2);
}

TEST(TestGroup_value, value_map)
{
    ClassValue v1 = ClassValue{1000, 0, 1000};

    CHECK_EQUAL(v1.map(1, 0, 10, 0, 1000), 100);
    CHECK_EQUAL(v1.map(2, 0, 10, 0, 1000), 200);
    CHECK_EQUAL(v1.map(3, 0, 10, 0, 1000), 300);
    CHECK_EQUAL(v1.map(4, 0, 10, 0, 1000), 400);
    CHECK_EQUAL(v1.map(5, 0, 10, 0, 1000), 500);
    CHECK_EQUAL(v1.map(6, 0, 10, 0, 1000), 600);
    CHECK_EQUAL(v1.map(7, 0, 10, 0, 1000), 700);
    CHECK_EQUAL(v1.map(8, 0, 10, 0, 1000), 800);
    CHECK_EQUAL(v1.map(9, 0, 10, 0, 1000), 900);
    CHECK_EQUAL(v1.map(10, 0, 10, 0, 1000), 1000);

    CHECK_EQUAL(v1.map(1, 0, 7, 0, 252), 36);
    CHECK_EQUAL(v1.map(2, 0, 7, 0, 252), 72);
    CHECK_EQUAL(v1.map(3, 0, 7, 0, 252), 108);
    CHECK_EQUAL(v1.map(4, 0, 7, 0, 252), 144);
    CHECK_EQUAL(v1.map(5, 0, 7, 0, 252), 180);
    CHECK_EQUAL(v1.map(6, 0, 7, 0, 252), 216);
    CHECK_EQUAL(v1.map(7, 0, 7, 0, 252), 252);

    CHECK_EQUAL(v1.map(1, 0, 6, 0, 252), 42);
    CHECK_EQUAL(v1.map(2, 0, 6, 0, 252), 84);
    CHECK_EQUAL(v1.map(3, 0, 6, 0, 252), 126);
    CHECK_EQUAL(v1.map(4, 0, 6, 0, 252), 168);
    CHECK_EQUAL(v1.map(5, 0, 6, 0, 252), 210);
    CHECK_EQUAL(v1.map(6, 0, 6, 0, 252), 252);

    CHECK_EQUAL(v1.map(1, 8, 1, 0, 252), 252);
    CHECK_EQUAL(v1.map(2, 8, 1, 0, 252), 216);
    CHECK_EQUAL(v1.map(3, 8, 1, 0, 252), 180);
    CHECK_EQUAL(v1.map(4, 8, 1, 0, 252), 144);
    CHECK_EQUAL(v1.map(5, 8, 1, 0, 252), 108);
    CHECK_EQUAL(v1.map(6, 8, 1, 0, 252), 72);
    CHECK_EQUAL(v1.map(7, 8, 1, 0, 252), 36);

    CHECK_EQUAL(v1.map(1, 1, 7, 7, 1), 7);
    CHECK_EQUAL(v1.map(2, 1, 7, 7, 1), 6);
    CHECK_EQUAL(v1.map(3, 1, 7, 7, 1), 5);
    CHECK_EQUAL(v1.map(4, 1, 7, 7, 1), 4);
    CHECK_EQUAL(v1.map(5, 1, 7, 7, 1), 3);
    CHECK_EQUAL(v1.map(6, 1, 7, 7, 1), 2);
    CHECK_EQUAL(v1.map(7, 1, 7, 7, 1), 1);
}
