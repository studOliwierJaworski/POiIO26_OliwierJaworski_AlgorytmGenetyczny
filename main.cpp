#include <iostream>
#include <cstdlib>  // uzywamy srand
#include <time.h>
#include <vector>

#include "TCandidate.h"
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"
#include "TCandidate_Zad3.h"
#include "TPopulation.h"
#include "TAlgorithm.h"

using namespace std;


int main() {

  srand(time(0));

    TCandidate_Zad1 wzorzec;

    TPopulation pop{ 10 , &wzorzec};
    pop.calculate();
    pop.info_short();
    cout << endl;

    cout << "Wylosowani osobnicy: \n";

    for (int i = 0; i < 10; i++) {

        TCandidate* can = pop.promote_candidate();
        int id = pop.get_candidate_index(can);
        cout << "#" << id << ", ";
    }

   cout << endl;

  return 0;
}