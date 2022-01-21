//
// Created by Sezer Çakır on 21.01.2022.
//
#include "matrix.hpp"

int main(){
    try
    {
        Eigen::MatrixXd eigenMat    =       Eigen::MatrixXd::Identity(4,4);
        myMatrix mat{4,4};            mat.setRandom();

        // * operator overloading
        if ( (mat * eigenMat).getMat() == mat.getMat() )
            std::cout << "Succes * overload\n";
        // == operator overload
        if ( myMatrix(mat * eigenMat) == mat.getMat() )
            std::cout << "Succes == operator\n";

    }
    catch (...)
    {
        std::cout << std::exception().what();
    }

    return 0;

}

