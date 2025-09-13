# Sustav za rezervaciju vlakova

Ovo je mali C++ projekt koji sam napravio kao vježbu.  
Ideja je bila napraviti jednostavan sustav u kojem korisnici mogu kreirati račun, prijaviti se i rezervirati sjedalo u vlaku.

Program se pokreće u konzoli i radi preko jednostavnog menija (unos brojeva).  
Trenutno se svi podaci čuvaju samo dok je program pokrenut (nema spremanja u datoteku).

## Što se može raditi?

- dodavati vlakove (model i broj sjedala)
- dodavati vožnje (polazište, odredište, vrijeme polaska i dolaska)
- registrirati novog korisnika
- prijaviti se s ID-jem korisnika
- rezervirati sjedalo i pregledati svoje karte

##  Kako pokrenuti?

Projekt je rađen u CLion-u, ali može se otvoriti u bilo kojem C++ okruženju.  
Treba samo buildati i pokrenuti `main.cpp`.

## Motivacija

Ovaj projekt sam napravio jer sam često putovao vlakom u školu i uvijek me zanimalo kako bi izgledalo kada bih sam pokušao napraviti jednostavan sustav za rezervaciju vlakova.  
Htio sam spojiti sve što sam do sada naučio u jedan konkretan projekt.

Kroz rad na ovom projektu naučio sam:

- kako koristiti `regex` za provjeru korisničkog unosa  
- kako implementirati provjeru unosa 'int' vrijednost.
- kako koristiti `shared_ptr` za upravljanje objektima u memoriji  
- kako razdvojiti klase u `.h` i `.cpp` datoteke

Ovo je moj prvi veći pokušaj da povežem više klasa i koncepata u jednu aplikaciju, i mislim da mi je dosta pomoglo da bolje razumijem objektno orijentirano programiranje.

## Autor

Mihael Stipic
GitHub: [MihaelStipic](https://github.com/MihaelStipic)
