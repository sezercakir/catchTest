//
// Created by PC-N-XXX on 1.02.2022.
//

#define CATCH_CONFIG_MAIN
#include "test_main.hpp"
#include "matcher.hpp"

SCENARIO("DB Constructor"){
    GIVEN("DB is given and user"){
        DB database("ITU DB", 10);
        database.addUser(data("Sezer",1));
        database.addUser(data("Ahmet",2));
        database.addUser(data("Tuğba",3));
        WHEN("Search user in DB"){
            data wanted("Sezer",1);
            CHECK_THAT(wanted, searchDB(database));
        }
    }
}

