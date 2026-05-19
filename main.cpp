#include <iostream>
#include <cstdlib>  // uzywamy srand
#include <time.h>
#include <vector>

#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"
#include "TKlasa.h"

using namespace std;
/*
int main() {

    TKlasa* wsk_obiekt1 = new TKlasa(-3);
    TKlasa* wsk_obiekt2 = new TKlasa(0);
    TKlasa* wsk_obiekt3 = new TKlasa(5);

    wsk_obiekt1->info();
    (*wsk_obiekt2).info();
    wsk_obiekt3->info();

    delete wsk_obiekt1;
    delete wsk_obiekt2;
    delete wsk_obiekt3;


    /* poprzedni kod
    srand(time(0));

    TPopulation pop(10);

    cout << "Zaraz po utworzeniu obiektu klasy TPopulation";
    pop.info();
    cout << "\n\n";

    cout << "Po wykonanych obliczeniach:";
    pop.calculate();
    pop.info();
    cout << "\n\n";

    cout << "Najlepszy osobnik: ";
    pop.get_best_candidate().info();

    */
 //   return 0;
//}

