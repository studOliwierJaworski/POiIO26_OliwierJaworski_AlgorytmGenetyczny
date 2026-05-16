//
// Created by Oliwier Jaworski on 12/05/2026.
//
#pragma once

#include <string>

class TParam {

private:
    // Parametry składowe klasy
    std::string name;
    double x_start, x_end, dx;
    int val_id;

public:
    // Konstruktor klasy
    TParam(double x_start, double x_end, double dx);
    TParam(double x_start, double x_end, double dx, double val);
    TParam(std::string name, double x_start, double x_end, double dx);
    TParam(std::string name, double x_start, double x_end, double dx, double val);

    // Definicja funkcji składowych
    void set_name(std::string name) { this->name = name; }
    std::string get_name() {return name; }

    void set_range(double x_start, double x_end, double dx);

    void set_rand_val();
    void set_val(double val) {val_id = get_val_id(val); }
    double get_val() {return x_start + val_id * dx; }

    // Bonusowa funkcja do wyświetlania stanu obiektu
    void info();

private:
    int get_val_id(double val);

};