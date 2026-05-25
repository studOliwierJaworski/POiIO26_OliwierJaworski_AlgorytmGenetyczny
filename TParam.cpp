//
// Created by Oliwier Jaworski on 12/05/2026.
//
#include <iostream>
#include <math.h>   // uzywamy fabs
#include <cstdlib>  // uzywamy rand

#include "TParam.h"

using namespace std;

TParam::TParam(double x_start, double x_end, double dx) : name{""}
{
    set_range(x_start, x_end, dx);
    //name = "";
    set_rand_val();
}

TParam::TParam(double x_start, double x_end, double dx, double val) : TParam::TParam(x_start, x_end, dx)
// uzywamy konstruktora delegujacego - czesc rzeczy jest juz uzupelniania z niego i tylko dodajemy nowe/kolejne zmienne
{
    //set_range(x_start, x_end, dx);
    set_val(val);
    //name = "";
}

TParam::TParam(std::string name_val, double x_start, double x_end, double dx) : name{name_val}
{

    //set_name(name);
    set_range(x_start, x_end, dx);
    set_rand_val();
}

TParam::TParam(std::string name, double x_start, double x_end, double dx, double val) : TParam::TParam(name, x_start, x_end, dx)
{
    //set_name(name);
    //set_range(x_start, x_end, dx);
    set_val(val);
}

TParam::TParam(const TParam &oryginal) : name{oryginal.get_name()} {

    // Konstruktor kopiujący
    double x_start = oryginal.get_x_start();
    double x_end = oryginal.get_x_end();
    double dx = oryginal.get_dx();
    set_range(x_start, x_end, dx);

    double val = oryginal.get_val();
    set_val(val);

}

void TParam::set_range(double x_start, double x_end, double dx) {

    this->x_start = x_start;
    this->x_end = x_end;
    this->dx = dx;
}

void TParam::set_rand_val() {

    int vals_count = fabs(x_end - x_start) / dx + 1;
    val_id = rand() % vals_count;
}

int TParam::get_val_id(double val) {

    if (val < x_start) return 0;

    else if (val > x_end) return (x_end - x_start) / dx;

    else {
        double x = x_start;
        int _id = 0;

        while (fabs(x + _id * dx - val) > dx / 2) _id++;

        return _id;
    }
}

void TParam::info() {

    cout << "\n";
    cout << "==============================\n";
    cout << "== name: " << name << "\n";
    cout << "== range: [" << x_start << "; " << x_end << "; " << dx << "]\n";
    cout << "== value: " << get_val() << " \t (id: #" << val_id << ")\n";
    cout << "==============================\n\n";

}