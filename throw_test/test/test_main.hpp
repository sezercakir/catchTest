/**
 * @file    : throw_test project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 01 / Şubat / 2022
 * @code    : test_main.h file
 * @details : 
 */



#ifndef TEST_MAIN_HPP
#define TEST_MAIN_HPP

#include "catch.hpp"
#include <iostream>
#include <string>
#include <utility>

class data{
    std::string name;
    double money;
    int ID;
public:
    data(std::string n, double m , int id) : name(std::move(n)), money(m), ID(id){}
    data(){};
};

class DB{
    data* users;
    int size;
    std::string name;
    int count;
public:
    DB(std::string n, int s) : name(std::move(n)), size(s){
        count = 0;
        users = new data[s];
    }

    static void getSize() {
        throw std::runtime_error("ABC") ;
    }

    void resize();
    data* getUsers(){ return users;}
    void addUser(const data& user);

};

void DB::resize ()
{
    try {
        size_t newSize = size*2;
        data* newUsers = new data[newSize];
        std::copy(users, users+newSize, newUsers);
        size = newSize;
        delete users;
        users = newUsers;
    }
    catch (...) {
        
    }

}

void DB::addUser (const data & user)
{
    if (count == size)
        resize();
    users[count] = user;
    count++;
}


#endif /* TEST_MAIN_HPP */