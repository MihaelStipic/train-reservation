//
// Created by mihae on 9/12/2025.
//

#ifndef VLAK_H
#define VLAK_H
#include <string>
using namespace std;



class Vlak {
public:
    int id;
    static int next_id;
    string vrsta_vlaka;
    int broj_sjedala;
    int ukupno_sjedala;
public:
    Vlak(): id(next_id++), vrsta_vlaka(""), broj_sjedala(0), ukupno_sjedala(0) {}
    Vlak (string vrsta_vlaka_1, int broj_sjedala_1) : id (next_id++), vrsta_vlaka(vrsta_vlaka_1), broj_sjedala(broj_sjedala_1) , ukupno_sjedala(broj_sjedala_1)  {}
    int get_id_vlaka();
    string get_vrsta();

    int get_broj_sjedala();

};




#endif //VLAK_H
