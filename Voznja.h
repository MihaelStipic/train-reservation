//
// Created by mihae on 9/12/2025.
//

#ifndef VOZNJA_H
#define VOZNJA_H
#include "Vlak.h"
#include <memory>
#include <string>
using namespace std;


class Voznja {
public:
    shared_ptr<Vlak> vlak;

    int broj_voznje;
    static int next_id_voznje;
    string polaziste;
    string odrediste;
    string vrijeme_polaska;
    string vrijeme_dolaska;
    int broj_sjedala;
public:
    Voznja(): broj_voznje(next_id_voznje++),polaziste(""), vlak(nullptr), odrediste(""), vrijeme_dolaska(""), vrijeme_polaska(""),broj_sjedala(0) {
    }
    Voznja (shared_ptr<Vlak> v,string pol, string odr, string polazak, string dolazak, int br): vlak(v), polaziste(pol), odrediste(odr), vrijeme_dolaska(dolazak), vrijeme_polaska(polazak), broj_voznje(next_id_voznje++), broj_sjedala(br) {}
    void display();
    int id_voznje();



};

#endif //VOZNJA_H
