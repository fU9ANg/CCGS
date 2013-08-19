
#include <limits.h>
#include "gtest/gtest.h"

TEST (Arithmetic_Expressions, EQ)
{
    int a = 10;
    int b = 10;

    ASSERT_EQ (a, b);
}

TEST (Arithmetic_Expressions, NE)
{
    int a = 10;
    int b = 10;

    ASSERT_NE (a, b);
}

TEST (Arithmetic_Expressions, GE)
{
    int a = 10;
    int b = 10;

    ASSERT_GE (a, b);
}

TEST (Arithmetic_Expressions, LE)
{
    int a = 10;
    int b = 10;

    ASSERT_LE (a, b);
}

TEST (Arithmetic_Expressions, GT)
{
    int a = 10;
    int b = 10;

    ASSERT_GT (a, b);
}

TEST (Arithmetic_Expressions, LT)
{
    int a = 10;
    int b = 10;

    ASSERT_LT (a, b);
}

