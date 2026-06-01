//
// Created by Oliwier Jaworski on 26/05/2026.
//
#pragma once

#include "TCandidate.h"

class TCandidate_Zad2 : public TCandidate {

public:
    TCandidate_Zad2() : TCandidate() {

        init_vector();
    }

    TCandidate_Zad2(const TCandidate_Zad2 &oryginal) : TCandidate(oryginal) {}

    TCandidate* create() {

        return new TCandidate_Zad2();
    }

    TCandidate* create_copy() const {

        return new TCandidate_Zad2{ *this };
    }

    void rate() {

        double x1 = genotype[0].get_val();
        double x2 = genotype[1].get_val();

        mark = 100 * x1 + x2;
    }

protected:
    void init_vector();
};

inline void TCandidate_Zad2::init_vector() {    // dodałem inline

    genotype.push_back({"x1", 0, 10, 1});
    genotype.push_back({"x2", 11, 20, 2});

    gens_count = genotype.size();
}