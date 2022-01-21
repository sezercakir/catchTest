//
// Created by Sezer Çakır on 21.01.2022.
//

#include "test.hpp"


/// AIM:    REQUIRE_THAT(matrixA == Approx(matrixB).epsilon(1.e-12))


SCENARIO(){
    GIVEN("Matrices are given"){
        Eigen::MatrixXd mat = Eigen::MatrixXd::Random(4,4);
        CHECK(mat == ApproxMat(mat).epsilon(1.e-12));
        //REQUIRE_THAT(mat , ApproxMat(mat).epsilon(1.e-12));
    }
}


