//
// Created by Oliwier Jaworski on 18/05/2026.
//
#include <iostream>
#include <algorithm> // uzywamy max

#include "TPopulation.h"
#include "TCandidate_Zad1.h"

using namespace std;

unsigned int TPopulation::_id = 0;
unsigned int TPopulation::population_count = 0;

TPopulation::TPopulation(unsigned int cands_count, TCandidate* pattern) {

    _id = population_count;
    population_count++;

    candidates_count = cands_count;

    // utworzenie obiektów klasy TCandidate, będących elementami wektora candidates
    for (int i = 0; i < cands_count; i++) candidates.push_back(pattern->create());
}

TPopulation::TPopulation(const TPopulation &oryginal) {

    _id++;

    candidates_count = oryginal.candidates_count;
    best_val = oryginal.best_val;

    for (int i = 0; i < candidates_count; i++) {

        const TCandidate* wsk_os_org = oryginal.get_candidate_wsk(i);
        TCandidate* copy = wsk_os_org->create_copy();
        candidates.push_back(copy);
    }
}


void TPopulation::calculate() {

    double best_val = 0.0;  // lokalna (chwilowa) najlepsza wartość

    for (int i = 0; i < candidates_count; i++) {  // obliczanie po kolei wartości każdego osobnika oraz wyznaczenie najlepszej wartości

        candidates[i]->rate();
        double val = candidates[i]->get_mark();

        if (i == 0) best_val = val;
        else best_val = max(best_val, val);
    }

    this->best_val = best_val;  // zapisanie najlepszego wyniku
}

TCandidate* TPopulation::get_best_candidate() {

    int i = 0;

    while (candidates[i]->get_mark() != best_val) i++;   // aż trafimy w najlepszego osobnika

    return candidates[i];
}

void TPopulation::info() {

    cout << "\n\n";
    cout << "==== POPULATION #" << _id << " ====\n";

    for (int i = 0; i < candidates_count; i++) {
        cout << "== candidate#" << i << ": " << candidates[i]->get_mark() << "\n";
    }

    cout << "=========================\n\n";
}

const TCandidate* TPopulation::get_candidate_wsk(int _id) const {

    const TCandidate* wsk = candidates[_id];
    return wsk;
}
