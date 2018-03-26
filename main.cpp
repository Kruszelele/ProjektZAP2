#include "Macierz.h"

int main()
{
    srand (time(0));
    Macierz a("macierz1.txt");
    a.wydrukuj();

    Macierz b(5,5);
    b.losowanie();

    Macierz wynik(a.wiersze, a.kolumny);

    wynik=b-a;
    wynik.wydrukuj();
    wynik=a+a;
    wynik.wydrukuj();
    wynik.zapisz("wynik.txt");
    wynik=b.odwrotna();
    wynik.wydrukuj();
    wynik=b*a;
    wynik.wydrukuj();
    wynik=a/b;
    wynik.wydrukuj();

    return 0;
}
