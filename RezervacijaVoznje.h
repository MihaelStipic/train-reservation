//
// Created by mihae on 9/12/2025.
//

#ifndef REZERVACIJAVOZNJE_H
#define REZERVACIJAVOZNJE_H


#include <memory>
#include "Voznja.h"
#include "Korisnik.h"
class RezervacijaVoznje {
public:
    shared_ptr<Voznja> voznja;
    shared_ptr<Korisnik> korisnik;
    int redni_broj_sjedala;
};




#endif //REZERVACIJAVOZNJE_H
