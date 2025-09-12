//
// Created by mihae on 9/12/2025.
//

#ifndef KORISNIK_H
#define KORISNIK_H

#include <string>
using namespace std;

class Korisnik {
private:
    string ime;
    string prezime;
    string email;
    int id;
    static int next_id;
public:
    Korisnik () : ime(""), prezime(""), email(""), id(next_id++) {}
    Korisnik(string ime_1, string prezime_1, string email_1) : ime(ime_1), prezime(prezime_1), email(email_1), id(next_id++) {}
    int get_korisnik_id();
};



#endif //KORISNIK_H
