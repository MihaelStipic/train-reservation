cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Vlak.cpp
        Vlak.h
        Korisnik.cpp
        Korisnik.h
        Voznja.cpp
        Voznja.h
        RezervacijaVoznje.cpp
        RezervacijaVoznje.h
        Rezervacija.cpp
        Rezervacija.h)
