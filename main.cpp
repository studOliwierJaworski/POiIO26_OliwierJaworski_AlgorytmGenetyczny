#include <iostream>
#include <cstdlib>  // uzywamy srand
#include <time.h>

#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"

using namespace std;

int main() {

    srand(time(0));

    TPopulation pop(10);

    cout << "Zaraz po utworzeniu obiektu klasy TPopulation";
    pop.info();
    cout << "\n\n";

    cout << "Po wykonanych obliczeniach:";
    pop.calculate();
    pop.info();
    cout << "\n\n";

    return 0;
}
