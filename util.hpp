#ifndef UTIL_H
    #define UTIL_H (123456789)
    #include "omp.h"
    #include "stdlib.h"
    #include "math.h"
    #include "time.h"
    #include <vector>
    #include <stdio.h>
    #include <iostream>
    #include <stdexcept>
    #include <string>
    #include <functional>
    
    const double PI = 3.14159265359;
    const double E =  2.71828182846;

    typedef std::vector<double> array;
    typedef std::vector<std::vector<double>> array2D;
    typedef std::vector<std::vector<std::vector <double>>> array3D;
    typedef std::vector<size_t> i_array;
    typedef std::vector<std::vector<size_t>> i_array2D;
    typedef std::function <double(double, double, double, 
                                double, double, double,
                                double, double, double)> CouplingFunc;

    // Debugging
    void PrintMessage(std::string message);
    void RaiseException(std::string message);
    void PrintVector(const double v[3]);
    void PrintVector(const array &v);
    void PrintVector(const double v[3], std::string vecname);
    void PrintVector(const array &v, std::string vecname);

    // Vector operations
    double Mag(const array v);
    double MagPerp(const array v);
    double Dot(const array v1, const array v2);
    array Cross(const array v1, const array v2);
    array Hat(const array v);
    double Sign(const double x);
    double Heavyside(const double x);

    // Scalar functions
    double Gaussian(double x, double mu, double sigma);
#endif