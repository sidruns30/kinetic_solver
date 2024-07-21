#include "util.hpp"

double Sqr(const double x)
{
    return x*x;
}
/*
    Return the magnitude of a vector
*/
double Mag(const array v)
{
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

/*
    Return the magnitude of the x-y component of the vector
*/
double MagPerp(const array v)
{
    return sqrt(v[0]*v[0] + v[1]*v[1]);
}

/*
    Return the dot product between vectors v1 and v2
*/
double Dot(const array v1, const array v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

/*
    Return the cross product between vectors v1 and v2
    Result stored in v3
*/
array Cross(const array v1, const array v2)
{
    array v3 = {v2[2]*v1[1] - v2[1]*v1[2], 
                v2[0]*v1[2] - v2[2]*v1[0],
                v2[1]*v1[0] - v2[0]*v1[1]};
    return v3;
}

/*
    Return the unit vector of the input vector v
    Result stored in vhat
*/
array Hat(const array v)
{
    const double mag_v = Mag(v);
    array vhat = {v[0]/mag_v, v[1]/mag_v, v[2]/mag_v};
    return vhat;
}

/*
    Return the sign of x
    Edgecase: returns 0 when x is 0
*/
double Sign(const double x)
{
    if (x > 0.) return 1.;
    else if (x < 0.) return -1.;
    else return 0.;
}

/*
    Return the heavyside function x
*/
double Heavyside(const double x)
{
    if (x < 0.) return 0.; 
    else if (x > 0.) return 1.;
    else return 0.5;
}

/*
    Print a message to the output stream
*/
void PrintMessage(std::string message)
{
    std::cout << message << std::endl;
    return;
}

/*
    Throw an exception
*/
void RaiseException(std::string message)
{
    std::cerr << "An exception has occurred." << std::endl;
    throw std::runtime_error(message);
    return;
}

/*
    Print the components of a vector
    The same function is overloaded a few times
*/
void PrintVector(const double v[3])
{
    std::cout << "[" << v[0] << ", " << v[1] << ", " << v[2] << "]" << std::endl;
    return;
}

void PrintVector(const array &v)
{
    const size_t vec_size = v.size();
    std::cout << "Vector shape is " << vec_size << std::endl;
    if (vec_size < 20)
    {
        std::cout << "[";
        for (size_t ii=0; ii<vec_size; ii++)
        {
            std::cout << v[ii] << ", ";
        }
        std::cout << "]";
    }
    else
    {
        std::cout << "[";
        for (size_t ii=0; ii<10; ii++)
        {
            std::cout << v[ii] << ", ";
        }
        std::cout << " ... ";
        for (size_t ii=vec_size-10; ii<vec_size; ii++)
        {
            std::cout << v[ii] << ", ";
        }
        std::cout << "]";
    }
    std::cout << std::endl;
    return;
}

/*
    Print the components of a vector
*/
void PrintVector(const double v[3], std::string vecname)
{
    std::cout << "Vector: " << vecname << std::endl;
    std::cout << "[" << v[0] << ", " << v[1] << ", " << v[2] << "]" << std::endl;
    return;
}

/*
    Print the elements of a vector for debugging purposes
*/
void PrintVector(const array v, std::string vecname)
{
    const size_t vec_size = v.size();
    std::cout << "Vec: " << vecname << " shape is " << vec_size << std::endl;
    if (vec_size < 20)
    {
        std::cout << "[";
        for (size_t ii=0; ii<vec_size; ii++)
        {
            std::cout << v[ii] << ", ";
        }
        std::cout << "]";
    }
    else
    {
        std::cout << "[";
        for (size_t ii=0; ii<10; ii++)
        {
            std::cout << v[ii] << ", ";
        }
        std::cout << " ... ";
        for (size_t ii=vec_size-10; ii<vec_size; ii++)
        {
            std::cout << v[ii] << ", ";
        }
        std::cout << "]";
    }
    std::cout << std::endl;
    return;
}

/*
    Return a gaussian that integrates to unity
*/
double Gaussian(double x, double mu, double sigma)
{
    return 1 / (sigma * sqrt(2*PI)) * exp(-((x-mu)*(x-mu)) / (2*sigma*sigma));
}
