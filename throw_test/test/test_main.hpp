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

class my_exception: public std::exception
{
    std::string what_message;
public:
    explicit my_exception(std::string  msg) : what_message(std::move(msg)){}
    my_exception()= default;
    const char* what() const noexcept override{
        return what_message.c_str();
    }
};

class data{
    std::string name;
    int ID;
public:
    data(std::string n, int id) : name(std::move(n)), ID(id){}
    data(){};
    std::string getName() const { return name;}
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

    int getSize() const {
        return size;
    }
    static  void throwExc(){
        throw std::runtime_error("ABC") ;
    }

    void resize();
    data* getUsers(){ return users;}
    int getCount() { return count;}
    void addUser(const data& user);


};

void DB::resize ()
{
    if (users != nullptr)
        throw my_exception("Logic Error");
    int newSize = size*2;
    data* newArr = new data[newSize];
    std::copy(users, users + std::min(size, newSize), newArr);
    size = newSize;
    delete[] users;
    users = newArr;
}

void DB::addUser (const data & user)
{
    if (count == size)
        resize();
    users[count] = user;
    count++;
    if (users[count-1].getName() == "HTU")
        throw my_exception("Adding Error");
}


#endif /* TEST_MAIN_HPP */