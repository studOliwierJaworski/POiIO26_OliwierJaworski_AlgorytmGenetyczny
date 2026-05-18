//
// Created by Oliwier Jaworski on 13/05/2026.
//
#pragma once
#include "TParam.h"

#define GENS_COUNT 2

class TCandidate {

    TParam genotype[GENS_COUNT] =       // tablica z wszystkimi genami osobnika
    {
        TParam("x1", 0, 10, 1),
        TParam("x2", 0, 10, 1)
    };

    double mark;    // zmienna do przechowywania oceny osobnika

public:
    TCandidate();

    double get_mark() {return mark; }; // funkcja zwracająca ocenę
    void rate();    // funkcja do wyliczania oceny

    void info();    // funkcja wyświetlająca informacje o osobniku

private:
    void rand_gens_val();   // funkcja do losowania wartości początkowej genów/parametrów osobnika

};