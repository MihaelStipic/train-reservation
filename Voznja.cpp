//
// Created by mihae on 9/12/2025.
//

#include "Voznja.h"
#include <string>
#include <iostream>
using namespace std;

void Voznja::display() {
    cout<<"Vlak broj: "<< broj_voznje<<" polazi iz kolodvora: "<< polaziste<< " u " <<vrijeme_polaska<< " sati i dolazi na kolodvor "<<odrediste<< " u "<< vrijeme_dolaska<< " sati, broj dostupnih sjedala je: "<<broj_sjedala<<endl;
}

int Voznja::id_voznje() {
    return broj_voznje;
}

int Voznja::next_id_voznje = 1120;



