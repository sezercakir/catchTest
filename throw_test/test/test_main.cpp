/**
 * @file    : throw_test project file
 * @author  : Talha Sezer Çakır
 * @note    : szckrrr@gmail.com
 * @date    : 01 / Şubat / 2022
 * @code    : test_main.cpp file
 * @details : 
 */

#define CATCH_CONFIG_MAIN
#include "test_main.hpp"

SCENARIO("Test constructor","[tag]"){
    WHEN("First Initialize"){
        DB databse("ITU Database", 5);

        REQUIRE_THROWS(databse.getSize());
    }
}


