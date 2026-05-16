#include <iostream>
#include <cstdlib>  // uzywamy srand
#include <time.h>

#include "TParam.h"

using namespace std;


int main() {

    srand(time(0));

    TParam param1{1, 4, 1, 2};
    TParam param2{10, 20, 3};
    TParam param3{0,10,0.5, 3.3};
    TParam param4{"pies", 12, 24, 3, 2};


    cout << "param1";
    param1.info();

    cout << "param2";
    param2.info();

    cout << "param3";
    param3.info();

    cout << "param4";
    param4.info();

    param2.set_val(100);
    param3.set_val(7.5);

    cout << "==============\n";
    cout << "AFTER\n";
    cout << "==============\n\n";

    cout << "param2";
    param2.info();

    cout << "param3";
    param3.info();



    return 0;
}