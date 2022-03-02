#include <iostream>
#include "test/test_main.hpp"

int main ()
{
    DB database("ITU",10);
    database.addUser(data("sezr",1));
    database.addUser(data("a",2));
    database.addUser(data("c",3));
    database.delete_elmnt("sezr");


    return 0;
}
