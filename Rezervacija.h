//
// Created by mihae on 9/12/2025.
//

#ifndef REZERVACIJA_H
#define REZERVACIJA_H
#include "Vlak.h"
#include "Voznja.h"
#include "Korisnik.h"
#include "RezervacijaVoznje.h"
#include <vector>


class Rezervacija {
public:
    vector<shared_ptr<Korisnik>> korisnici;
    vector<shared_ptr<Vlak>> vlakovi;
    vector<shared_ptr<Voznja>> voznje;
    vector<RezervacijaVoznje> rezervacije;
public:
    void dodaj_Korisnika(shared_ptr<Korisnik> k);
    shared_ptr<Korisnik> pronadi_korisnika(int id);
    bool postoji_vlak(int id);
    void dodaj_vlak(shared_ptr<Vlak> v);
    void prikazi_vlakove();
    void dodaj_voznju(shared_ptr<Voznja> v);
    shared_ptr<Vlak> pronadi_vlak(int id);


    void prikazi_voznje();
    bool prazna_voznja();
    void dodaj_rezervaciju(shared_ptr<Korisnik> k, shared_ptr<Voznja> v,int redni_broj);
};



#endif //REZERVACIJA_H
