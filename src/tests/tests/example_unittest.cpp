#include <gtest/gtest.h>
#include <example/example.hpp>

namespace example
{
    TEST(ExampleLibrary, Sum2Integers)
    {
        auto result = example::sum(1, 1);
        EXPECT_EQ(result, 2);
    }

    TEST(ExampleLibrary, Sum2Floats)
    {
        auto result = example::sum(float(1.1), float(1.1));
        EXPECT_EQ(result, float(2.2));
    }

    TEST(ExampleLibrary, Sum2Doubles)
    {
        auto result = example::sum(double(1.1), double(1.1));
        EXPECT_EQ(result, double(2.2));
    }
}
