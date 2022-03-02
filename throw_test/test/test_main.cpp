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
        WHEN("Feza Buzluca Added")
        {
            /// In faulty situations we can send throw directly. In addUser func exception'll not be thrown.
            REQUIRE_NOTHROW(database.addUser(data("Feza Buzluca", 1)));
        }
        WHEN("HTU Added")
        {
            /// In faulty situations we can send throw directly. In addUser func exception'll be thrown.
            REQUIRE_THROWS(database.addUser(data("HTU", 1)));
        }
    }
}
SCENARIO("THROW_AS","[tag]"){
    WHEN("First Initialize"){
        DB databse("ITU Database", 5);
        /// std::logic error test'll will fail
        AND_WHEN("Resize Operation Called"){
            THEN("Exception is caught") {
                CHECK_THROWS_AS(databse.resize(), my_exception);
            }
        }
    }
}







