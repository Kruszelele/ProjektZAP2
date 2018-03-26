#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class Macierz {
public:
    int wiersze;
    int kolumny;
    double **zawartosc;

    Macierz(int _wiersze, int _kolumny);
    Macierz(string _nazwapliku);

    ~Macierz();

    Macierz(const Macierz&);

    void losowanie ();
    void wydrukuj ();
    void zapisz (string nazwapliku);
    double policz_wyznacznik(int rozmiar);
    Macierz odwrotna();

    Macierz & operator=(const Macierz &wzor);
    friend Macierz operator+(Macierz&, Macierz&);
    friend Macierz operator-(Macierz&, Macierz&);
    friend Macierz operator*(Macierz&, Macierz&);
    friend Macierz operator/(Macierz&, Macierz&);
};

#endif // MACIERZ_H
