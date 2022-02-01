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
    GIVEN("Database is given"){
        DB database("ITU Lecturer DB",10);
        WHEN("Element Added"){
            /// In faulty situations we can send throw directly. ID is int not double 0.5
            CHECK_THROWS(database.addUser(data("Feza Buzluca", 0.5)), throw my_exception{});
        }
    }
}





