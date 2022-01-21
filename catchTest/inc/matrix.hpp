//
// Created by Sezer Çakır on 21.01.2022.
//

#ifndef CATCHTEST_MATRIX_HPP
#define CATCHTEST_MATRIX_HPP

#include <iostream>
#include <Eigen/Dense>
#include <utility>

class myMatrix : public std::__1::error_code {
private:
    Eigen::MatrixXd mat{};
public:
    myMatrix(int r, int c) : mat(r,c){}
    explicit myMatrix(Eigen::MatrixXd inMat) : mat(std::move(inMat)){}
    void setRandom(){ mat.setRandom(); }
    Eigen::MatrixXd getMat(){ return mat;}
    myMatrix operator* (const Eigen::MatrixXd&);
    bool operator== (const Eigen::MatrixXd&);
};


myMatrix myMatrix::operator * (const Eigen::MatrixXd &inMatrix) {
    if (mat.rows() != inMatrix.cols())
    {
        throw std::domain_error("Matrix shape is not valid for multiplication");
    }
    else
    {
        return myMatrix(mat * inMatrix);
    }
}

bool myMatrix::operator == ( const Eigen::MatrixXd &inMat ) {
    return mat == inMat;
}

#endif //CATCHTEST_MATRIX_HPP
