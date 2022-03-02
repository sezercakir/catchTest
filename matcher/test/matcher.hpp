//
// Created by PC-N-XXX on 1.02.2022.
//

#ifndef MATCHER_MATCHER_HPP
#define MATCHER_MATCHER_HPP
#include "test_main.hpp"

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


#endif //MATCHER_MATCHER_HPP
