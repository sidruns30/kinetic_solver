#include "pgen.hpp"

// User needs to initialize the following functions
double W00( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W01( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W10( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W11( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W02( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W12( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W20( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W21( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double W22( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    return 0;
}
double DeltaRate( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q)
{
    double rate = 1.;
    rate *= Gaussian(k_z, p_z + q_z, sigma_par);
    rate *= Gaussian(k_perp*cos(phi_k), p_perp*cos(phi_p) + q_perp*cos(phi_q), sigma_perp);
    rate *= Gaussian(k_perp*sin(phi_k), p_perp*sin(phi_p) + q_perp*sin(phi_q), sigma_perp);
    return rate;
}
