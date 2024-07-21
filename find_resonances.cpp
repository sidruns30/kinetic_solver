#include "find_resonances.hpp"

extern array k_par, k_perp;

/*
    Return a 2-dimensional array containing the indices of resonances triad
    The first dimension has the shape k_par x k_perp and interates over the k wave vector
    The second dimension contains 4 x n_res triads for a given k_par and k_perp combination,
    i.e., indices of p_par, p_perp, q_par and q_perp
    The resonances are not exact and are within a margin of delta_k, defined in pgen.hpp

    The functions are defined for the following interactions:
    AFF: Alfven -> Fast + Fast
    AFA: Alfven -> Fast + Alfven
    AAA: Alfven -> Alfven + Alfven
    FAF: Fast -> Alfven + Fast
    FAA: Fast -> Alfven + Alfven
*/

i_array ResonancesAFA(  const float k_par_current, const float k_perp_current,
                        const array &k_par, const array &k_perp, size_t &nres_AFA)
{
  i_array resonant_indices;
  const size_t n_par = k_par.size();
  const size_t n_perp = k_perp.size();
  // Loop over p
  for (size_t ipar=0; ipar<n_par; ipar++)
  {
    const float p_par = k_par[ipar];
    if (fabs(fabs(k_par_current) - fabs(p_par)) < delta_k)
    {
      for (size_t iperp=0; iperp<n_perp; iperp++)
      {
        const float p_perp = k_perp[iperp];
        if (fabs(fabs(p_perp) - sqrt(Sqr(k_par_current) - Sqr(p_par))) < delta_k)
        {
          // Loop over q
          for (size_t jpar=0; jpar<n_par; jpar++)
          {
            const float q_par = k_par[jpar];
            if (fabs(k_par_current - p_par - q_par) < delta_k)
            {
              for (size_t jperp=0; jperp<n_perp; jperp++)
              {
                const float q_perp = k_perp[jperp];
                if (fabs(k_perp_current - p_perp - q_perp) < delta_k)
                {
                  resonant_indices.push_back(ipar);
                  resonant_indices.push_back(iperp);
                  resonant_indices.push_back(jpar);
                  resonant_indices.push_back(jperp);
                  nres_AFA ++;
                }
              }
            }
          }
        }
      }
    }
  }
  return resonant_indices;
}

i_array ResonancesAAA(  const float k_par_current, const float k_perp_current,
                        const array &k_par, const array &k_perp, size_t &nres_AAA)
{
  i_array resonant_indices;
  const size_t n_par = k_par.size();
  const size_t n_perp = k_perp.size();
  // Loop over p
  for (size_t ipar=0; ipar<n_par; ipar++)
  {
    const float p_par = k_par[ipar];
    if (fabs(k_par_current + p_par) < delta_k)
    {
      for (size_t iperp=0; iperp<n_perp; iperp++)
      {
        const float p_perp = k_perp[iperp];
        // Loop over q
        for (size_t jpar=0; jpar<n_par; jpar++)
        {
          const float q_par = k_par[jpar];
          if (fabs(q_par) < delta_k)
          {
            for (size_t jperp=0; jperp<n_perp; jperp++)
            {
              const float q_perp = k_perp[jperp];
              if (fabs(k_perp_current - p_perp - q_perp) < delta_k)
              {
                resonant_indices.push_back(ipar);
                resonant_indices.push_back(iperp);
                resonant_indices.push_back(jpar);
                resonant_indices.push_back(jperp);
                nres_AAA ++;
              }
            }
          }
        }
      }
    }
  }
  return resonant_indices;
}

i_array ResonancesFFA(  const float k_par_current, const float k_perp_current,
                        const array &k_par, const array &k_perp, size_t &nres_FFA)
{
  const float kmag_current = sqrt(Sqr(k_par_current) + Sqr(k_perp_current));
  i_array resonant_indices;
  const size_t n_par = k_par.size();
  const size_t n_perp = k_perp.size();
  // Loop over p
  for (size_t ipar=0; ipar<n_par; ipar++)
  {
    const float p_par = k_par[ipar];
    if (fabs(kmag_current - fabs(p_par)) < delta_k)
    {
      for (size_t iperp=0; iperp<n_perp; iperp++)
      {
        const float p_perp = k_perp[iperp];
        if (fabs(fabs(p_perp) - sqrt(Sqr(kmag_current) - Sqr(p_par))) < delta_k)
        {
          // Loop over q
          for (size_t jpar=0; jpar<n_par; jpar++)
          {
            const float q_par = k_par[jpar];
            if (fabs(k_par_current - p_par - q_par) < delta_k)
            {
              for (size_t jperp=0; jperp<n_perp; jperp++)
              {
                const float q_perp = k_perp[jperp];
                if (fabs(k_perp_current - p_perp - q_perp) < delta_k)
                {
                  resonant_indices.push_back(ipar);
                  resonant_indices.push_back(iperp);
                  resonant_indices.push_back(jpar);
                  resonant_indices.push_back(jperp);
                  nres_FFA ++;
                }
              }
            }
          }
        }
      }
    }
  }
  return resonant_indices;
}

i_array ResonancesFAA(  const float k_par_current, const float k_perp_current,
                        const array &k_par, const array &k_perp, size_t &nres_FAA)
{
  const float kmag_current = sqrt(Sqr(k_par_current) + Sqr(k_perp_current));
  i_array resonant_indices;
  const size_t n_par = k_par.size();
  const size_t n_perp = k_perp.size();
  // Loop over p
  for (size_t ipar=0; ipar<n_par; ipar++)
  {
    const float p_par = k_par[ipar];
    if (fabs(kmag_current - fabs(p_par)) < delta_k)
    {
      for (size_t iperp=0; iperp<n_perp; iperp++)
      {
        const float p_perp = k_perp[iperp];
        // Loop over q
        for (size_t jpar=0; jpar<n_par; jpar++)
        {
          const float q_par = k_par[jpar];
          if (fabs(k_par_current - p_par - q_par) < delta_k)
          {
            for (size_t jperp=0; jperp<n_perp; jperp++)
            {
              const float q_perp = k_perp[jperp];
              if (fabs(k_perp_current - p_perp - q_perp) < delta_k)
              {
                resonant_indices.push_back(ipar);
                resonant_indices.push_back(iperp);
                resonant_indices.push_back(jpar);
                resonant_indices.push_back(jperp);
                nres_FAA ++;
              }
            }
          }
        }
      }
    }
  }
  return resonant_indices;
}

void FindAllResonances(i_array2D &indices_AFA, i_array2D &indices_AAA, i_array2D &indices_FFA, 
                      i_array2D &indices_FAA)
{
  const size_t n_par = k_par.size();
  const size_t n_perp = k_perp.size();
  size_t nres_AFA=0, nres_AAA=0, nres_FFA=0, nres_FAA=0;
  indices_AFA.reserve(n_par * n_perp);
  indices_AAA.reserve(n_par * n_perp);
  indices_FFA.reserve(n_par * n_perp);
  indices_FAA.reserve(n_par * n_perp);

  #pragma omp parallel for schedule (dynamic) reduction(+:nres_AFA,nres_AAA,nres_FFA,nres_FAA)
  for (size_t ii=0; ii<n_par; ii++)
  {
    for (size_t jj=0; jj<n_perp; jj++)
    {
      const float k_par_current = k_par[ii];
      const float k_perp_current = k_perp[jj];
      const size_t index = ii * n_perp + jj;

      indices_AFA[index] = ResonancesAFA(k_par_current, k_perp_current, k_par, k_perp, nres_AFA);
      indices_AAA[index] = ResonancesAAA(k_par_current, k_perp_current, k_par, k_perp, nres_AAA);
      indices_FFA[index] = ResonancesFFA(k_par_current, k_perp_current, k_par, k_perp, nres_FFA);
      indices_FAA[index] = ResonancesFAA(k_par_current, k_perp_current, k_par, k_perp, nres_FAA);
    }
  }
  PrintMessage("Resonances found!");
  std::cout << "AFA: " << nres_AFA << ", AAA: " << nres_AAA << ", FFA: " << nres_FFA << ", FAA: " << nres_FAA << "\n";
  return;
}