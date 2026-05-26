#include <iostream>
#include <cstdlib>  // uzywamy srand
#include <time.h>
#include <vector>

#include "TCandidate.h"
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"


using namespace std;

int main() {

  srand(time(0));

  int osobnik;
  int ilosc_os;

  cout << "Ktory osobnik [0-2]: ";
  cin >> osobnik;
  cout << "Ilu osobnikow utworzyc? ";
  cin >> ilosc_os;


  vector<TCandidate*> candidates;

  for (int i = 0; i < ilosc_os; i++) {
    if (osobnik == 0) {
      candidates.push_back(new TCandidate{});
    } else if (osobnik == 1) {
      candidates.push_back(new TCandidate_Zad1{});
    } else if (osobnik == 2) {
      candidates.push_back(new TCandidate_Zad2{});
    } else {
      cout << "Bledny osobnik";
    }
  }

  for (int i = 0; i < candidates.size(); i++) {

    candidates[i]->rate();
    candidates[i]->info();
  }

  for (int i = 0; i < candidates.size(); i++) {

    delete candidates[i];
  }

  return 0;
}