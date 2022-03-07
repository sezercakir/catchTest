//
// Created by PC-N-XXX on 7.03.2022.
//

#include <gtest/gtest.h>


TEST(TestConst, TestName)
{
    std::vector<int> vec(2);
    ASSERT_EQ(2, vec.size());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}