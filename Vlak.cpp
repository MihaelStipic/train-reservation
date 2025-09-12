//
// Created by mihae on 9/12/2025.
//

#include "Vlak.h"

string Vlak::get_vrsta() {
    return vrsta_vlaka;
}

int Vlak::get_broj_sjedala() {
    return broj_sjedala;
}

int Vlak::get_id_vlaka() {
    return id;
}

int Vlak::next_id = 6320;