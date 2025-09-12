#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include "Vlak.h"
#include "Voznja.h"
#include "Korisnik.h"
#include "RezervacijaVoznje.h"
#include "Rezervacija.h"
using namespace std;

//provjera (HH:MM)
#include <regex>

bool provjeri_vrijeme(const string &vrijeme) {
    regex pattern("^([01]?[0-9]|2[0-3]):[0-5][0-9]$");
    // [01]? moze imati 0 ili 1 na pocetku
    // [0-9] pokriva 0-9, 10-19
    // 2[0-3] pokriva 20-23
    // [0-5] prva znamenka moze biti od 0-5
    // [0-9] druga znamenka od 0-9
    return regex_match(vrijeme, pattern);
}


bool provjeri_email(const string &email) {
    regex pattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    // {2,} min. 2 slova poslije tocke
    return regex_match(email, pattern);
}




int main() {



    int broj;
    Rezervacija R;
    shared_ptr<Vlak> L1 = make_shared<Vlak>("HG 456KL", 23);
    R.dodaj_vlak(L1);
    shared_ptr<Vlak> L2 = make_shared<Vlak>("MS 324KA", 45);
    R.dodaj_vlak(L2);
    shared_ptr<Vlak> L3 = make_shared<Vlak>("AE 543TR", 120);
    R.dodaj_vlak(L3);

    shared_ptr<Voznja> R1 = make_shared<Voznja>(L1, "Strizivojna-Vrpolje", "Osijek", "6:27", "7:22", L1->get_broj_sjedala());
    R.dodaj_voznju(R1);
    shared_ptr<Voznja> R2 = make_shared<Voznja>(L2, "Strizivojna-Vrpolje", "Osijek", "10:35", "11:25", L2->get_broj_sjedala());
    R.dodaj_voznju(R2);

    shared_ptr<Voznja> R5 = make_shared<Voznja>(L2, "Osijek", "Strizivojna-Vrpolje", "7:27", "8:19", L2->get_broj_sjedala());
    R.dodaj_voznju(R5);

    shared_ptr<Voznja> R8 = make_shared<Voznja>(L1, "Osijek", "Strizivojna-Vrpolje", "20:35", "21:25", L1->get_broj_sjedala());
    R.dodaj_voznju(R8);

    shared_ptr<Korisnik> K;

    do {
        cout<< "Dobrodosli u online train webshop"<<endl;
        cout<< "1. Prijava u sustav"<<endl;
        cout<< "2. Izrada racuna"<<endl;
        cout<< "3. Dodaj vlak"<<endl;
        cout<< "4. Dodaj voznju"<<endl;
        cout<< "5. Prikazi voznje"<<endl;

        cout<< "0. Izlaz"<<endl;
        cin>>broj;
        switch (broj) {
            case 1: {
                int brk;
                cout<<"Unesite broj korisnika: "<<endl;
                cin>>brk;

                K = R.pronadi_korisnika(brk);
                if (K == nullptr) {
                    cout<<"Korisnik ne postoji!";
                }else {
                    cout<< "Uspjesna prijava."<<endl;
                    int broj1;
                    do {
                        cout<< "Dobrodosli u online train webshop"<<endl;
                        cout<< "1. Prikaz voznji"<<endl;
                        cout<< "2. Prikaz mojih karata"<<endl;
                        cout<< "3. Rezervacija karte"<<endl;

                        cout<< "0. Izlaz"<<endl;
                        cin>>broj1;
                        switch (broj1) {
                            case 1: {
                                if (R.voznje.empty()) {
                                    cout<<"Nema upisanih voznji!"<<endl;
                                    break;
                                }
                                R.prikazi_voznje();
                                break;
                            }
                            case 3: {
                                if (R.prazna_voznja()) {
                                    cout << "Nema dostupnih voznji!"<<endl;
                                    break;
                                }
                                R.prikazi_voznje();
                                cout << "Unesite ID voznje koju zelite rezervirati: ";
                                int id_voznje;
                                cin >> id_voznje;

                                shared_ptr<Voznja> v = nullptr;
                                for (auto &voznja : R.voznje) {
                                    if (voznja->id_voznje() == id_voznje) {
                                        v = voznja;
                                        break;
                                    }
                                }

                                if (!v) { // za krivi unos
                                    cout << "Nepostojeca voznja!"<<endl;
                                    break;
                                }

                                if (v->broj_sjedala<1) {
                                    cout<<"Nedovoljno sjedala!"<<endl;
                                    break;
                                }

                                R.dodaj_rezervaciju(K, v,v->broj_sjedala);
                                cout << "Uspjesno rezervirana karta!"<<endl;
                                cout<<"Rezerviran broj sjedala je sjedalo broj "<<v->broj_sjedala<<endl;
                                v->broj_sjedala--;
                                break;

                            }
                            case 2: {
                                cout << "Vase rezervacije:"<<endl;
                                bool ima = false;
                                for (auto &r : R.rezervacije) {
                                    if (r.korisnik->get_korisnik_id() == K->get_korisnik_id()) {
                                        cout << "Voznja ID: " << r.voznja->id_voznje()
                                             << ", polazak: " << r.voznja->polaziste
                                             << ", odrediste: " << r.voznja->odrediste
                                             << ", redni broj sjedala: " << r.redni_broj_sjedala << endl;
                                        ima = true;
                                    }
                                }
                                if (!ima) cout << "Nemate rezervacija."<<endl;
                                break;

                            }
                        }
                    }while(broj1!=0);

                }

                break;

            }
            case 2: {
                string ime;
                string prezime;
                string email;

                cout<< "Unesite ime korisnika: "<<endl;
                cin.ignore();
                getline(cin, ime);

                cout<< "Unesite prezime korisnika: "<<endl;
                getline(cin, prezime);

                do {
                    cout << "Unesite email korisnika: " << endl;
                    getline(cin, email);
                    if (!provjeri_email(email)) {
                        cout << "Neispravan email format! Pokusajte ponovno." << endl;
                    }
                } while (!provjeri_email(email));



                auto Izrada = make_shared <Korisnik>(ime, prezime, email);
                cout<< "Uspjesna izrada racuna. Korisnik s brojem: "<<Izrada->get_korisnik_id()<<endl;
                R.dodaj_Korisnika(Izrada);











                break;
            }
            case 3: {


                int broj_sjedala;


                string ime_vlaka;

                cin.ignore();
                cout<<"Unesite ime vlaka: "<<endl;
                getline(cin, ime_vlaka);
                cout<<"Unesite broj sjedala: "<<endl;

                //Pravilan unos int
                while (true) {
                    cin >> broj_sjedala;

                    if (cin.fail()) {
                        cout << "Greška: morate unijeti broj!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                }
                cout << "Vlak: " << ime_vlaka << ", broj sjedala: " << broj_sjedala << endl;


                shared_ptr<Vlak> V = make_shared<Vlak>(ime_vlaka, broj_sjedala);

                R.dodaj_vlak(V);


                break;
            }
            case 4: {
                if (R.vlakovi.empty()) {
                    cout<<"Nema vlakova!"<<endl;
                    break;
                }
                cout<<"Vlakovi u pogonu su: "<<endl;
                R.prikazi_vlakove();
                cout<< "Unesite broj vlaka: "<<endl;
                int broj_vlaka;

                //Pravilan unos int
                while (true) {
                    cin >> broj_vlaka;

                    if (cin.fail()) {
                        cout << "Greška: morate unijeti broj!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                }
                if (!R.postoji_vlak(broj_vlaka)) {
                    cout<<"Vlak ne postoji!"<<endl;
                    break;

                }
                shared_ptr<Vlak> P = R.pronadi_vlak(broj_vlaka);

                string polaziste;
                string odrediste;
                string polazak;
                string dolazak;


                cin.ignore();


                cout<<"Odredite polaziste vlaka: "<<endl;
                getline(cin, polaziste);
                cout<<"Odredite odrediste vlaka: "<<endl;
                getline(cin, odrediste);

                do {
                    cout << "Odredite vrijeme polaska (HH:MM): ";
                    cin >> polazak;
                    if (!provjeri_vrijeme(polazak)) {
                        cout << "Neispravan format! Pokusajte ponovno." << endl;
                    }
                } while (!provjeri_vrijeme(polazak));

                do {
                    cout << "Odredite vrijeme dolaska (HH:MM): ";
                    cin >> dolazak;
                    if (!provjeri_vrijeme(dolazak)) {
                        cout << "Neispravan format! Pokusajte ponovno." << endl;
                    }
                } while (!provjeri_vrijeme(dolazak));



                auto T = make_shared <Voznja> (P, polaziste, odrediste, polazak, dolazak,P->broj_sjedala);

                R.dodaj_voznju(T);


                cout<<"Polazak iz kolodvora: "<< polaziste<< " u " <<polazak<< " sati i dolazi na kolodvor "<<odrediste<< " u "<< dolazak<< " sati."<<endl;





                break;

            }
            case 5: {
                if (R.prazna_voznja()) {
                    cout<<"Nisu upisane voznje!"<<endl;
                    break;
                }
                R.prikazi_voznje();

                break;
            }
            case 0: {
                cout<<"Hvala sto ste koristili nas sustav!"<<endl;
                break;
            }
            default:
                cout << "Nepostojeca opcija." << endl;
        }
    }while (broj !=0);


}
