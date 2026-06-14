//
// Created by Oliwier Jaworski on 19/05/2026.
//
#include <iostream>
#include <math.h>
#include <bitset>
#include <string>

#include "TAlgorithm.h"
#include "TPopulation.h"

using namespace std;

TAlgorithm::TAlgorithm(TCandidate* pattern,
    unsigned int candidates_count,
    unsigned int max_population_count,
    unsigned int min_improvement_proc) {

    this->pattern = pattern;
    stop_max_population_count = max_population_count;
    stop_min_improvement_proc = min_improvement_proc;

    wsk_population_pres = new TPopulation{candidates_count, pattern};
}

TAlgorithm::~TAlgorithm() {

    delete wsk_population_pres;
    delete wsk_population_prev;

    cout << "Usunieto obiekt klasy TAlgorithm";
}

void TAlgorithm::run() {

    bool stop = false;

    while (!wsk_population_prev || !stop) {

        wsk_population_pres->calculate();

        cout << "== Population #" << wsk_population_pres->get_id();
        cout << " || best val: " << wsk_population_pres->get_best_val() << endl;

        stop = is_stop();

        if (!stop) {

            unsigned int candidates_count = wsk_population_pres->get_candidates_count();

            delete wsk_population_prev;
            wsk_population_prev = wsk_population_pres;

            // chwilowe rozwiązanie - tworzenie kolejnej losowej populacji
            //wsk_population_pres = new TPopulation{candidates_count, pattern};


            // tworzymy nową pustą populację na nowe pokolenie

           wsk_population_pres = new TPopulation{candidates_count, pattern};

            // Ewolucja - tworzymy nowe pokolenie parami
            for (int i = 0; i < candidates_count; i += 2) {

                // 1. Selekcja rodziców z poprzedniej populacji
                TCandidate* rodzic1 = wsk_population_prev->promote_candidate();
                TCandidate* rodzic2 = wsk_population_prev->promote_candidate();

                // 2. Tworzenie potomków
                TCandidate* potomek1 = pattern->create();
                TCandidate* potomek2 = pattern->create();

                // 3. Krzyżowanie
                krzyzowanie(rodzic1, rodzic2, potomek1, potomek2);

                // 4. Mutacja potem


                // 5. Dodanie do nowej populacji
                wsk_population_pres->replace_candidate(i, potomek1);
                wsk_population_pres->replace_candidate(i + 1, potomek2);
            }
        }

        }

        if (wsk_population_pres->get_id() == 25) return;
    }


void TAlgorithm::krzyzowanie(TCandidate* rodzic1, TCandidate* rodzic2, TCandidate* potomek1, TCandidate* potomek2) {

    int szansa = rand() % 100 + 1;

    if (szansa <= 75) {

        // Pobieramy geny i zamieniami je na bitowy format
        // zlepiamy 3 geny rodzica w 1 ciąg 24 bitowy

        std::string r1_g0 = std::bitset<8>(rodzic1->get_gen_raw_id(0)).to_string();
        std::string r1_g1 = std::bitset<8>(rodzic1->get_gen_raw_id(1)).to_string();
        std::string r1_g2 = std::bitset<8>(rodzic1->get_gen_raw_id(2)).to_string();

        std::string bity_rodzic1 = r1_g0 + r1_g1 + r1_g2;

        std::string r2_g0 = std::bitset<8>(rodzic2->get_gen_raw_id(0)).to_string();
        std::string r2_g1 = std::bitset<8>(rodzic2->get_gen_raw_id(1)).to_string();
        std::string r2_g2 = std::bitset<8>(rodzic2->get_gen_raw_id(2)).to_string();

        std::string bity_rodzic2 = r2_g0 + r2_g1 + r2_g2;


        // cięcie i krzyżowanie
        int ciecie = rand() % 23 + 1;

        std::string bity_potomek1 = bity_rodzic1.substr(0, ciecie) + bity_rodzic2.substr(ciecie);
        std::string bity_potomek2 = bity_rodzic2.substr(0, ciecie) + bity_rodzic1.substr(ciecie);


        // wypisanie do przetestowania działania
        cout << "\nzaszło krzyżowanie" << endl;
        cout << "Punkt ciecia: " << ciecie << endl;
        cout << "Rodzic 1: " << bity_rodzic1.substr(0, ciecie) << "|" << bity_rodzic1.substr(ciecie) << endl;
        cout << "Rodzic 2: " << bity_rodzic2.substr(0, ciecie) << "|" << bity_rodzic2.substr(ciecie) << endl;

        cout << "Potomek 1: " << bity_potomek1 << endl;
        cout << "Potomek 2: " << bity_potomek2 << endl;


        // Powrót na liczby i zapis do potomków
        // 24 bitowy ciąg Potomka 1 z powrotem na kawałki po 8 bitów
        int id1_g0 = std::bitset<8>(bity_potomek1.substr(0, 8)).to_ulong();
        int id1_g1 = std::bitset<8>(bity_potomek1.substr(8, 8)).to_ulong();
        int id1_g2 = std::bitset<8>(bity_potomek1.substr(16, 8)).to_ulong();

        potomek1->set_gen_raw_id(0, id1_g0);
        potomek1->set_gen_raw_id(1, id1_g1);
        potomek1->set_gen_raw_id(2, id1_g2);


        int id2_g0 = std::bitset<8>(bity_potomek2.substr(0, 8)).to_ulong();
        int id2_g1 = std::bitset<8>(bity_potomek2.substr(8, 8)).to_ulong();
        int id2_g2 = std::bitset<8>(bity_potomek2.substr(16, 8)).to_ulong();

        potomek2->set_gen_raw_id(0, id1_g0);
        potomek2->set_gen_raw_id(1, id1_g1);
        potomek2->set_gen_raw_id(2, id1_g2);

    } else {
        // brak krzyżowania

        for (int i = 0; i < 3; i++) {

            potomek1->set_gen_raw_id(i, rodzic1->get_gen_raw_id(i));
            potomek2->set_gen_raw_id(i, rodzic2->get_gen_raw_id(i));

        }
    }
}



bool TAlgorithm::is_max_population() {

    unsigned int _id_pres = wsk_population_pres->get_id();
    return (_id_pres == stop_max_population_count);
}

bool TAlgorithm::is_min_improvement() {

    TPopulation population_pres = (*wsk_population_pres);
    TPopulation population_prev = (*wsk_population_prev);

    double best_val_pres = population_pres.get_best_val();
    double best_val_prev = population_prev.get_best_val();

    int improvement = fabs(best_val_prev - best_val_pres) / best_val_prev * 100;
    return (improvement <= stop_min_improvement_proc);
}

bool TAlgorithm::is_stop() {

    bool stop = false;

    if (!wsk_population_prev) // rozpatrywana pierwsza populacja
    {
        stop = is_max_population();
    }
    else {
        bool stop_case1 = is_max_population();
        bool stop_case2 = is_min_improvement();
        stop = stop_case1 || stop_case2;
    }
    return stop;
}

