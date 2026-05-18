//
// Created by Oliwier Jaworski on 18/05/2026.
//
#pragma once

#include <vector>
#include "TCandidate.h"

class TPopulation {

    unsigned int candidates_count;  // liczba osobników w populacji
    std::vector<TCandidate> candidates; // zbiornik na obiekty klasy TCandidate
    double best_val = 0;    // najlepszy obecny wynik

public:
    TPopulation(unsigned int cands_count = 10); // konstruktor z jednym parametrem - liczba osobników w populacji
    void calculate();
    TCandidate get_best_candidate();

    void info();    // f. do wyswietlania informacji na ekranie

};