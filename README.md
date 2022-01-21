# [Catch2](https://github.com/catchorg/Catch2) Test Framework Document&Practices

This repo was created as an example of using the catch test framework with many c++ libraries. They can provide depth to users in testing the Catch and other libraries.

## Directories
There is basic structure of cpp project that consists of inc,src adn test directories in all project folder.

#### Catch Approx Comparison with [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) Library Matrices
* In this [project](https://github.com/sezercakir/catchTest/tree/main/catchTest), derived class from Approx class of Catch namespace to comparison between Eign::MatrixXd objects with considering double precision.
* Main idea is operator overload in test.cpp file.


