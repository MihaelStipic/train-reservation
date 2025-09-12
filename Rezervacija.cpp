//
// Created by mihae on 9/12/2025.
//

#include "Rezervacija.h"

#include <iostream>
using namespace std;


void Rezervacija::dodaj_rezervaciju(shared_ptr<Korisnik> k, shared_ptr<Voznja> v, int redni_broj) {
    rezervacije.push_back({v, k,redni_broj});
}

bool Rezervacija::prazna_voznja() {
    return voznje.empty();
}

void Rezervacija::prikazi_voznje() {
    for (auto &x : voznje) {
        x->display();
    }
}



shared_ptr<Vlak> Rezervacija::pronadi_vlak(int id) {
    for (auto &x : vlakovi) {
        if (x->get_id_vlaka() == id) {
            return x;
        }
    }
    return nullptr;
}

void Rezervacija::dodaj_voznju(shared_ptr<Voznja> v) {
    voznje.push_back(v);
}

void Rezervacija::prikazi_vlakove() {
    for (auto &x : vlakovi) {
        cout<<"Id vlaka: "<< x->get_id_vlaka()<<". Broj vlaka: "<<x->get_vrsta()<<". Broj sjedala: "<<x->get_broj_sjedala()<<endl;
    }

}

void Rezervacija::dodaj_vlak(shared_ptr<Vlak> v) {
    vlakovi.push_back(v);
}


bool Rezervacija::postoji_vlak(int id) {
    for (auto &x : vlakovi) {
        if (x->get_id_vlaka() == id) {
            return true;
        }
    }
    return false;

}

void Rezervacija::dodaj_Korisnika(shared_ptr<Korisnik> k) {
    korisnici.push_back(k);
}

shared_ptr<Korisnik> Rezervacija::pronadi_korisnika(int id) {
    for (auto &x : korisnici) {
        if (x->get_korisnik_id() == id) {
            return x;
        }

    }
    return nullptr;
}
