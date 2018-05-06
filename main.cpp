#include "Macierz.h"

int main(){
    cout << "napisz, co chcesz zrobic: dodac, odjac, pomnozyc, podzielic lub odwrocic macierze"<< endl;
    string odpowiedz;
    cin >> odpowiedz;
    if (odpowiedz=="dodac"){
        string macierza, macierzb;
        cout << "podaj nazwy plikow z macierzami wejsciowymi" << endl;
        cin >> macierza;
        Macierz a(macierza);
        cin >> macierzb;
        Macierz b(macierzb);
        if ((a.wiersze==b.wiersze)&&(a.kolumny==b.kolumny)){
            Macierz wynik (a.wiersze, a.kolumny);
            wynik=a+b;
            wynik.zapisz("wynik.txt");
            cout << "macierz wynikowa zostala zapisana do pliku o nazwie: wynik.txt. Czy chcesz wyswietlic wynik w konsoli? Napisz: tak, nie" << endl;
            cin >> odpowiedz;
            if (odpowiedz=="tak"){
                wynik.wydrukuj();
            }
        }
        else{
            cout << "operacja niemozliwa do wykonania" << endl;
            return 1;
        }
    }
    else if (odpowiedz=="odjac"){
        string macierza, macierzb;
        cout << "podaj nazwy plikow z macierzami wejsciowymi" << endl;
        cin >> macierza;
        Macierz a(macierza);
        cin >> macierzb;
        Macierz b(macierzb);
        if ((a.wiersze==b.wiersze)&&(a.kolumny==b.kolumny)){
            Macierz wynik (a.wiersze, a.kolumny);
            wynik=a+b;
            wynik.zapisz("wynik.txt");
            cout << "macierz wynikowa zostala zapisana do pliku o nazwie: wynik.txt. Czy chcesz wyswietlic wynik w konsoli? Napisz: tak, nie" << endl;
            cin >> odpowiedz;
            if (odpowiedz=="tak"){
                wynik.wydrukuj();
            }
        }
        else{
            cout << "operacja niemozliwa do wykonania" << endl;
            return 1;
        }
    }
    else if (odpowiedz=="pomnozyc"){
        string macierza, macierzb;
        cout << "podaj nazwy plikow z macierzami wejsciowymi" << endl;
        cin >> macierza;
        Macierz a(macierza);
        cin >> macierzb;
        Macierz b(macierzb);
        if (a.kolumny==b.wiersze){
            Macierz wynik (a.wiersze, b.kolumny);
            wynik=a*b;
            wynik.zapisz("wynik.txt");
            cout << "macierz wynikowa zostala zapisana do pliku o nazwie: wynik.txt. Czy chcesz wyswietlic wynik w konsoli? Napisz: tak, nie" << endl;
            cin >> odpowiedz;
            if (odpowiedz=="tak"){
                wynik.wydrukuj();
            }
        }
        else{
            cout << "operacja niemozliwa do wykonania" << endl;
            return 0;
        };
    }
    else if (odpowiedz=="podzielic"){
        string macierza, macierzb;
        cout << "podaj nazwy plikow z macierzami wejsciowymi" << endl;
        cin >> macierza;
        Macierz a(macierza);
        cin >> macierzb;
        Macierz b(macierzb);
        if ((a.wiersze==a.kolumny)&&(b.policz_wyznacznik(b.wiersze)!=0)&&(a.kolumny==b.kolumny)){
            Macierz wynik (a.wiersze, b.kolumny);
            wynik=a/b;
            wynik.zapisz("wynik.txt");
            cout << "macierz wynikowa zostala zapisana do pliku o nazwie: wynik.txt. Czy chcesz wyswietlic wynik w konsoli? Napisz: tak, nie" << endl;
            cin >> odpowiedz;
            if (odpowiedz=="tak"){
                wynik.wydrukuj();
            }

        }
        else{
            cout << "operacja niemozliwa do wykonania" << endl;
            return 1;
        }
    }
    else if (odpowiedz=="odwrocic"){
        string macierza;
        cout << "podaj nazwe pliku z macierza wejsciowa" << endl;
        cin >> macierza;
        Macierz a(macierza);
        if ((a.wiersze==a.kolumny)&&(a.policz_wyznacznik(a.wiersze)!=0)){
            Macierz wynik (a.wiersze, a.kolumny);
            wynik=a.odwrotna();
            wynik.zapisz("wynik.txt");
            cout << "macierz wynikowa zostala zapisana do pliku o nazwie: wynik.txt. Czy chcesz wyswietlic wynik w konsoli? Napisz: tak, nie" << endl;
            cin >> odpowiedz;
            if (odpowiedz=="tak"){
                wynik.wydrukuj();
            }

        }
        else{
            cout << "operacja niemozliwa do wykonania" << endl;
            return 1;
        }
    }


    return 0;
}
