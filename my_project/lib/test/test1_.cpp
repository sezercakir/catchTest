/// @author Talha Sezer Çakır
/// @brief fundementals of google test framework [https://github.com/google/googletest]
///        implementation and description are made by refrence the book "Modern C++ Programming Cookbook 2017 - Marius Bancila"
/// @date 6.01.2022

#include "lib.hpp"
#include "gtest/gtest.h"

/*
    TEST(TestCaseName, TesstName)  template for test case initialization
    Google gives the test users the opportunity to filter their tests on the command line according to the test case and test name values.
    Controlling process is made with ASSERT* and EXPECT* operations. Details below.
*/

TEST(TestConstruction, TestConstructor){

    auto p = point3d(1,2,3,1.2,2.4);

    /// ASSERT_* and EXPECT_* macros is valid for the strings object but NOT C Strings. You can check this source for C strings. \
    [https://chromium.googlesource.com/external/github.com/google/googletest/+/refs/tags/release-1.8.0/googletest/docs/Primer.md#string-comparison]

    ASSERT_EQ(p.getx(),1);
    ASSERT_EQ(p.gety(),2);      ///  ASSERT versions generate fatal failures when they fail, and abort the current function.
    ASSERT_EQ(p.getz(),3);
    ASSERT_NE(p.getx(),10);     /// val1 != val2
    ASSERT_LT(p.getx(),2);      /// val1 < val2
    ASSERT_LE(p.getx(),1);      /// val1 <= val2
    ASSERT_GT(p.getx(),0);      /// val1 > val2
    ASSERT_GE(p.getx(),1);      /// val1 >= val2
}

TEST(TestConstruction, TestOrigin){

    auto p = point3d::origin(); /// origin functions returned point3d with zero initialization {}
    EXPECT_EQ(p.getx(), 0);
    EXPECT_EQ(p.gety(), 0);     ///  EXPECT_* versions generate nonfatal failures, which don‘t abort the current function. Usually EXPECT_* are preferred.
    EXPECT_EQ(p.getz(), 0);
}

TEST(TestConstruction, TestFloatingPoints){

    /// Due to the rounding errors, EXPECT_EQ or ASSERT_EQ is not suitable for floating points.

    auto p = point3d(1,2,3,1.2,2.4);

    /// Verifies that the two float values val1 and val2 are approximately equal, to within 4 ULPs from each other. For more detail ULP error bound \
    [https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/]


    // EXPECT_FLOAT_EQ(p.getdx(),p.getdy());        because dx_ and dy_ data are double FLOAT_EQ is not used in here
    // ASSERT_FLOAT_EQ(p.getdx(),p.getdy());

    EXPECT_DOUBLE_EQ(p.getdx(),p.getdy());
    ASSERT_DOUBLE_EQ(p.getdx(),p.getdy());

    double abs_error = 0.00001;
    EXPECT_NEAR(p.getdx(),p.getdy(),abs_error);     /// Verifies that the difference between val1 and val2 does not exceed the absolute error bound abs_error.
    ASSERT_NEAR(p.getdx(),p.getdy(),abs_error);
}

int main(int argc, char const *argv[])
{
    ::testing::InitGoogleTest(); /// initializes the framework and must be called before
    return RUN_ALL_TESTS(); /// automatically detects and calls all the tests defined with either the TEST() or TEST_F() macro \
                                             TEST_F represenet TESTCASE with fixture struct.
}
