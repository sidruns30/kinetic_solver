#include "find_resonances.hpp"

int main()
{
  IntializeArrays();
  i_array2D indices_AFA, indices_AAA, indices_FFA, indices_FAA;
  FindAllResonances(indices_AFA, indices_AAA, indices_FFA, indices_FAA);
  return 0;
}