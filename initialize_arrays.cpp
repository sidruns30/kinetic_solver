#include "initialize_arrays.hpp"

/*
  Function to average Wij over the phi angles
*/
void AverageWOverPhi(double k_z, double k_perp,
          double p_z, double p_perp,
          double q_z, double q_perp,
          double &Wij, CouplingFunc Wfunc)
{
  extern const int resolution_phi;
  double dphi = 2 * PI / resolution_phi;
  Wij = 0.;
  for (int ii=0; ii<resolution_phi; ii++)
  {
    double phi_k = dphi * ii;
    for (int jj=0; jj<resolution_phi; jj++)
    {
      double phi_p = dphi * jj;
      for (int kk=0; kk<resolution_phi; kk++)
      {
        double phi_q = dphi * kk;
        Wij += Wfunc(k_z, k_perp, phi_k, p_z, p_perp, phi_p, q_z, q_perp, phi_q);
      }
    }
  }
  Wij *= dphi * dphi * dphi;
  return;
}

/*
  Do the same averaging as above, but for an array
*/
void AverageWarrayOverPhi(array &Warr, array k_perp, array k_par, CouplingFunc Wfunc)
{
  const int n_perp = resolution_perp * 2 + 1;
  const int n_par = resolution_par * 2 + 1;
  array p_perp, p_par, q_perp, q_par;
  p_perp = k_perp;
  q_perp = k_perp;
  p_par = k_par;
  q_par = k_par;

  Warr.reserve(n_perp*n_perp*n_perp*n_par*n_par*n_par);
  PrintMessage("Shape of W local is " + std::to_string(n_perp*n_perp*n_perp*n_par*n_par*n_par));

  #pragma omp parallel for
  for (int i_k_perp=0; i_k_perp<n_perp; i_k_perp++)
  {
    for (int i_k_par=0; i_k_par<n_par; i_k_par++)
    {
      for (int i_p_perp=0; i_p_perp<n_perp; i_p_perp++)
      {
        for (int i_p_par=0; i_p_par<n_par; i_p_par++)
        {
          for (int i_q_perp=0; i_q_perp<n_perp; i_q_perp++)
          {
            for (int i_q_par=0; i_q_par<n_par; i_q_par++)
            {
              long int index = i_q_par + i_q_perp * n_par + 
                               i_p_par * n_par * n_perp + 
                               i_p_perp * n_par * n_perp * n_par + 
                               i_k_par *  n_par * n_perp * n_par * n_perp + 
                               i_k_perp * n_par * n_perp * n_par * n_perp * n_par;
              AverageWOverPhi(k_par[i_k_par], k_perp[i_k_perp], 
                              p_par[i_p_par], p_perp[i_p_perp],
                              q_par[i_q_par], q_perp[i_q_perp], Warr[index], Wfunc);
              PrintMessage(std::to_string(Warr[index]));
            }
          }
        }
      }
    }
  }
  return;
}

/*
  Allocate and initialize A, W and k_perp, k_par arrays
*/
void IntializeArrays()
{
  // Initialize the k arrays
  const int n_perp = resolution_perp * 2 + 1;
  const int n_par = resolution_par * 2 + 1;
  const double k_perp_rat = pow(10., log10(abs_k_perp_max/abs_k_perp_min) / resolution_perp);
  const double k_par_rat = pow(10., log10(abs_k_par_max/abs_k_par_min) / resolution_par);
  
  PrintMessage("Number of waves is " + std::to_string(Nwaves));
  PrintMessage("Number of wavevectors in perp direction is " + std::to_string(n_perp));
  PrintMessage("Number of wavevectors in z direction is " + std::to_string(n_par));

  for (int ii=0; ii<resolution_perp; ii++) k_perp.push_back(-abs_k_perp_max * pow(k_perp_rat, -(double)ii));
  k_perp.push_back(0.);
  for (int ii=0; ii<resolution_perp; ii++) k_perp.push_back(abs_k_perp_min * pow(k_perp_rat, (double)ii));
  PrintMessage("K perp initialized!");
  //PrintVector(k_perp, "K_perp");


  for (int ii=0; ii<resolution_par; ii++) k_par.push_back(-abs_k_par_max * pow(k_par_rat, -(double)ii));
  k_par.push_back(0.);
  for (int ii=0; ii<resolution_par; ii++) k_par.push_back(abs_k_par_max * pow(k_par_rat, (double)ii));
  PrintMessage("K par initialized!");
  //PrintVector(k_par, "K_par");

  // Initialize the A array
  InitializeA(A);
  PrintMessage("A initialized!");
  //PrintVector(A[0], "A[0]");

  // Initialize the W array
  W.reserve(Nwaves);
  for (int ii=0; ii<Nwaves; ii++) W[ii].reserve(Nwaves);

  
  // Now the most computationally expensive bit to compute the coefficients
  if (Nwaves == 1)
  {
    AverageWarrayOverPhi(W[0][0], k_perp, k_par, W00);
    PrintMessage("W00 initialized!");
  }

  else if (Nwaves == 2)
  {
    AverageWarrayOverPhi(W[0][0], k_perp, k_par, W00);
    PrintMessage("W00 initialized!");
    AverageWarrayOverPhi(W[0][1], k_perp, k_par, W01);
    PrintMessage("W01 initialized!");
    AverageWarrayOverPhi(W[1][0], k_perp, k_par, W10);
    PrintMessage("W10 initialized!");
    AverageWarrayOverPhi(W[1][1], k_perp, k_par, W11);
    PrintMessage("W11 initialized!");
  }

  else if (Nwaves == 3)
  {
    AverageWarrayOverPhi(W[0][0], k_perp, k_par, W00);
    PrintMessage("W00 initialized!");
    AverageWarrayOverPhi(W[0][1], k_perp, k_par, W01);
    PrintMessage("W01 initialized!");
    AverageWarrayOverPhi(W[1][0], k_perp, k_par, W10);
    PrintMessage("W10 initialized!");
    AverageWarrayOverPhi(W[1][1], k_perp, k_par, W11);
    PrintMessage("W11 initialized!");
    AverageWarrayOverPhi(W[0][2], k_perp, k_par, W02);
    PrintMessage("W02 initialized!");
    AverageWarrayOverPhi(W[1][2], k_perp, k_par, W12);
    PrintMessage("W12 initialized!");
    AverageWarrayOverPhi(W[2][0], k_perp, k_par, W20);
    PrintMessage("W20 initialized!");
    AverageWarrayOverPhi(W[2][1], k_perp, k_par, W21);
    PrintMessage("W21 initialized!");
    AverageWarrayOverPhi(W[2][2], k_perp, k_par, W22);
    PrintMessage("W22 initialized!");
  }
  
  PrintMessage("Initialization Complete!");
  return;
}
