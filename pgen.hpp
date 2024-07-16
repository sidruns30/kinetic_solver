#ifndef PGEN_H
    #define PGEN_H (123456789)
    #include "util.hpp"

    // User specifies the following
    extern const int Nwaves = 3;
    extern const int resolution_perp = 10;
    extern const int resolution_par = 10;
    extern const float abs_k_perp_min = 0.1;
    extern const float abs_k_perp_max = 100;
    extern const float abs_k_par_min = 0.1;
    extern const float abs_k_par_max = 100;
    extern const float sigma_par = 0.1;
    extern const float sigma_perp = 0.1;

    // User specifies these functions in the cpp file
    double W00( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W01( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W10( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W11( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W02( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W12( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W20( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W21( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double W22( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);
    double DeltaRate( double k_z, double k_perp, double phi_k,
                double p_z, double p_perp, double phi_p,
                double q_z, double q_perp, double phi_q);

#endif