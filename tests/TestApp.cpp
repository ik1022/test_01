#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup){};

TEST(FirstTestGroup, FirstTest)
{
    CHECK(true);
    LONGS_EQUAL(2, 2);
}

int main(int ac, const char **av)
{
    /* These checks are here to make sure assertions outside test runs don't crash */
    CHECK(true);
    LONGS_EQUAL(1, 1);

    return CommandLineTestRunner::RunAllTests(ac, av);
}
