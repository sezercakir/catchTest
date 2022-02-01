//
// Created by PC-N-XXX on 1.02.2022.
//

#ifndef MATCHER_TEST_MAIN_HPP
#define MATCHER_TEST_MAIN_HPP

#include "catch.hpp"
#include <iostream>
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
    data* getUsers() const { return users;}
    int getCount() const { return count;}
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

/// Matcher Class
class SearchDB_Matcher : public Catch::MatcherBase<data>{
    DB db;
public:
    explicit SearchDB_Matcher(DB  in) : db(std::move(in)){}

    /// Performs the test for this matcher
    bool match( data const& user) const override{
        for (size_t i = 0; i < db.getSize(); i++){
            if (db.getUsers()[i].getName() == user.getName())
                return true;
        }
        return false;
    }

    /// implemented virtual func that is inherited
    std::string describe() const override {
        std::ostringstream ss;
        return ss.str();
    }

};

/// Builder function
inline SearchDB_Matcher searchDB(const DB& inDB){
    return SearchDB_Matcher(inDB);
}

#endif //MATCHER_TEST_MAIN_HPP
