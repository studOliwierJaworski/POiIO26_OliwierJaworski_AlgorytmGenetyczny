#include <iostream>
#include <cstdlib>  // uzywamy srand
#include <time.h>
#include <vector>

#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"
#include "TKlasa.h"
#include "TAlgorithm.h"

using namespace std;

int main() {

  srand(time(0));

  TParam gen{ "gen1", 0, 10, 0.1};
  gen.info();

  TParam gen_copy(gen);
  gen_copy.info();

  cout << "\n\n";
// ###########################################################
  TCandidate os1{};
  os1.rate();
  os1.info();

  TCandidate os_copy{ os1 };
  os_copy.info();

  cout << "\n\n";
// ###########################################################
  TPopulation pop1 {5};
  pop1.calculate();
  pop1.info();

  TPopulation pop_copy{ pop1 };
  pop_copy.info();

  cout << "\n\n";

  return 0;
}