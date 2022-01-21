//
// Created by Sezer Çakır on 21.01.2022.
//

#ifndef CATCHTEST_TEST_HPP
#define CATCHTEST_TEST_HPP
#include "catch.hpp"
#include <iostream>
#include <utility>
#include "matrix.hpp"

class ApproxMat : public Catch::Detail::Approx{
public:

    explicit ApproxMat(Eigen::MatrixXd inMat) : Catch::Detail::Approx(std::move(inMat)){}


};

#endif //CATCHTEST_TEST_HPP
