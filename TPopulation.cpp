//
// Created by Oliwier Jaworski on 18/05/2026.
//
#include <iostream>
#include <algorithm> // uzywamy max

#include "TPopulation.h"

using namespace std;

unsigned int TPopulation::_id = 0;

TPopulation::TPopulation(unsigned int cands_count) {

    _id++;
    candidates_count = cands_count;

    // utworzenie obiekyów klasy TCandidate, będących elementami wektora candidates
    for (int i = 0; i < cands_count; i++) candidates.push_back(TCandidate{});
}

void TPopulation::calculate() {

    double best_val = 0.0;  // lokalna (chwilowa) najlepsza wartość

    for (int i = 0; i < candidates_count; i++) {  // obliczanie po kolei wartości każdego osobnika oraz wyznaczenie najlepszej wartości

        candidates[i].rate();
        double val = candidates[i].get_mark();

        if (i == 0) best_val = val;
        else best_val = max(best_val, val);
    }

    this->best_val = best_val;  // zapisanie najlepszego wyniku
}

TCandidate TPopulation::get_best_candidate() {

    int i = 0;

    while (candidates[i].get_mark() != best_val) i++;   // aż trafimy w najlepszego osobnika

    return candidates[i];
}

void TPopulation::info() {

    cout << "\n\n";
    cout << "==== POPULATION #" << _id << " ====\n";

    for (int i = 0; i < candidates_count; i++) {
        cout << "== candidate#" << i << ": " << candidates[i].get_mark() << "\n";
    }

    cout << "=========================\n\n";
}
