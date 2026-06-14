//
// Created by Oliwier Jaworski on 13/05/2026.
//
#pragma once

#include <vector>
#include "TParam.h"

// #define GENS_COUNT 2

class TCandidate {

protected:  // dzięki temu będzie widoczne w klasach dziedzicząych - dla pozostałego kodu jak private
   /* TParam genotype[GENS_COUNT] =       // tablica z wszystkimi genami osobnika
    {
        TParam("x1", 0, 100, 1),
        TParam("x2", 0, 10, 1)
    }; */
    int gens_count = 0;
    std::vector<TParam> genotype;

    double mark;    // zmienna do przechowywania oceny osobnika

public:
    TCandidate();
    TCandidate(const TCandidate &oryginal);

    virtual TCandidate* create() = 0;
    virtual TCandidate* create_copy() const = 0;
    virtual ~TCandidate() {}

    double get_mark() const {return mark; }; // funkcja zwracająca ocenę
    virtual void rate() = 0;    // funkcja abstrakcyjna -> cala klasa abstrakcyjna

    void info();    // funkcja wyświetlająca informacje o osobniku

    int get_gen_raw_id(int gen_id) {return genotype[gen_id].get_raw_val_id(); }
    void set_gen_raw_id(int gen_id, int new_id) { genotype[gen_id].set_raw_val_id(new_id); }


protected:
    virtual void init_vector() = 0;

    void rand_gens_val();   // funkcja do losowania wartości początkowej genów/parametrów osobnika
    double get_gen_val(int gen_id) const {return genotype[gen_id].get_val();}
};


