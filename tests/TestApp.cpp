#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup){};

TEST(FirstTestGroup, FirstTest) { CHECK(true); }

int main(int ac, char **av) { return RUN_ALL_TESTS(ac, av); }
