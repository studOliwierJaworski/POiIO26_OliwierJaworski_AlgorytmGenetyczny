//
// Created by Oliwier Jaworski on 18/05/2026.
//
#pragma once

#include <vector>
#include "TCandidate.h"

class TPopulation {

    static unsigned int population_count;
    static unsigned int _id;
    unsigned int candidates_count;  // liczba osobników w populacji
    std::vector<TCandidate*> candidates; // zbiornik na obiekty klasy TCandidate
    double best_val = 0;    // najlepszy obecny wynik

public:
    TPopulation(unsigned int cands_count, TCandidate* pattern); // konstruktor z jednym parametrem - liczba osobników w populacji
    TPopulation(const TPopulation &oryginal);

    void calculate();
    TCandidate* get_best_candidate();

    unsigned int get_id() {return _id;}
    unsigned int get_candidates_count() { return candidates_count; }
    double get_best_val() {return best_val; }

    void info();    // f. do wyswietlania informacji na ekranie

private:
    const TCandidate* get_candidate_wsk(int _id) const;
};
