//
// Created by Oliwier Jaworski on 13/05/2026.
//
#pragma once
#include "TParam.h"

#define GENS_COUNT 2

class TCandidate {

protected:  // dzięki temu będzie widoczne w klasach dziedzicząych - dla pozostałego kodu jak private
    TParam genotype[GENS_COUNT] =       // tablica z wszystkimi genami osobnika
    {
        TParam("x1", 0, 100, 1),
        TParam("x2", 0, 10, 1)
    };

    double mark;    // zmienna do przechowywania oceny osobnika

public:
    TCandidate();
    TCandidate(const TCandidate &oryginal);

    double get_mark() const {return mark; }; // funkcja zwracająca ocenę
    virtual void rate();    // funkcja do wyliczania oceny

    void info();    // funkcja wyświetlająca informacje o osobniku

protected:
    void rand_gens_val();   // funkcja do losowania wartości początkowej genów/parametrów osobnika
    double get_gen_val(int gen_id) const {return genotype[gen_id].get_val();}
};


