#include "pgen.hpp"

// User needs to initialize the following functions
double DeltaRate( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
  double rate = 1.;
  rate *= Gaussian(k_par, p_par + q_par, sigma_par);
  rate *= Gaussian(k_perp*cos(phi_k), p_perp*cos(phi_p) + q_perp*cos(phi_q), sigma_perp);
  rate *= Gaussian(k_perp*sin(phi_k), p_perp*sin(phi_p) + q_perp*sin(phi_q), sigma_perp);
  return rate;
}

double W00( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W01( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W10( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W11( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W02( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W12( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W20( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W21( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}

double W22( double k_par, double k_perp, double phi_k,
                double p_par, double p_perp, double phi_p,
                double q_par, double q_perp, double phi_q)
{
    return 0 * DeltaRate(k_par, k_perp, phi_k, p_par, p_perp, phi_p, q_par, q_perp, phi_q);
}


/*
    Initialize the A array
    Ai array is the number of modes of wave i
    Every Ai array has a shape of k_perp x k_par
    Index j in each Ai array corresponds to j = n_par x k_perp + k_par
    Therefore k_perp = j // n_par and k_par = j - k_perp x npar
*/
void InitializeA(array2D &A)
{
    const int n_perp = resolution_perp * 2 + 1;
    const int n_par = resolution_par * 2 + 1;

    A.reserve(Nwaves);
    for (int wave_type=0; wave_type<Nwaves; wave_type++)
    {
      array Aj (n_perp*n_par);
      for (int i_perp=0; i_perp<n_perp; i_perp++)
      {
        for (int i_par=0; i_par<n_par; i_par++)
        {
          int index = i_perp * n_par + i_par;
          // Initialize here
          Aj[index] = 1.;
        }
      }
      A.push_back(Aj);
    }
    return;
}