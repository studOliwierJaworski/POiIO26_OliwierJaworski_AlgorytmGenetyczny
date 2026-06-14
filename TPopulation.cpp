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

TCandidate* TPopulation::promote_candidate() {      // zadanie ruletka

    int total_sum = 0;
    int current_sum = 0;

    for (int i = 0; i < candidates_count; i++) {

        // rzutujemy na int
        total_sum = (int)(total_sum + candidates[i]->get_mark());  // calkowity przedzial do losowania
    }

    int los = rand() % total_sum + 1;   // losowanie z ruletki

    for (int j = 0; j < candidates_count; j++) {

        current_sum = (int)(current_sum + candidates[j]->get_mark()); // przedziały do sprawdzania który osobnik

        if (los <= current_sum) {
            return candidates[j];
        }
    }
    cout << "Los jest bledny";
    // zwrócenie ostatniego osobnika przy blednym losie
    return candidates[candidates_count-1];
}

void TPopulation::replace_candidate(int index, TCandidate* new_candidate) {

    // usuwamy z pamięci domyślnie wygenerowanego kandydata w tym miejscu
    delete candidates[index];

    // nowy potomek w to miejsce
    candidates[index] = new_candidate;
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

int TPopulation::get_candidate_index(TCandidate* candidate) {

    for (int i = 0; i < candidates_count; i++) {
        // Porównujemy wskaźniki
        if (candidates[i] == candidate) {
            return i; // Zwracamy indeks osobnika
        }
    }
    return -1;
}

void TPopulation::info() {

    cout << "\n\n";
    cout << "==== POPULATION #" << _id << " ====\n";

    for (int i = 0; i < candidates_count; i++) {
        cout << "== candidate#" << i << ": " << candidates[i]->get_mark() << "\n";
    }

    cout << "=========================\n\n";
}

void TPopulation::info_short() {    // do ruletki
    for (int i = 0; i < candidates_count; i++) {
        cout << "Candidate#" << i << ": " << candidates[i]->get_mark() << "\n";
    }
}

const TCandidate* TPopulation::get_candidate_wsk(int _id) const {

    const TCandidate* wsk = candidates[_id];
    return wsk;
}
