    #include "Macierz.h"

void Macierz::losowanie (){
    for (int i=0; i<wiersze; i++)
        for (int j=0; j<kolumny; j++)
            zawartosc[i][j]=1+(10-1)*rand()/int(RAND_MAX);

}

Macierz:: ~Macierz(){
    for (int i=0; i<wiersze; i++)
        delete []zawartosc[i];
    delete []zawartosc;
}

Macierz:: Macierz (int _wiersze,int _kolumny){
    wiersze = _wiersze;
    kolumny = _kolumny;
    zawartosc=new double *[wiersze];
    for (int i=0; i<wiersze; i++)
        zawartosc[i]=new double [kolumny];
    for (int i=0; i<wiersze; i++)
        for (int j=0; j<kolumny; j++)
            zawartosc[i][j]=0;

}

Macierz:: Macierz (const Macierz &wzor){
    wiersze = wzor.wiersze;
    kolumny = wzor.kolumny;
    zawartosc=new double *[wiersze];
    for (int i=0; i<wiersze; i++)
        zawartosc[i]=new double [kolumny];
    for (int i=0; i<wiersze; i++)
        for (int j=0; j<kolumny; j++)
            zawartosc[i][j]=wzor.zawartosc[i][j];
}

Macierz ::Macierz(string _nazwapliku){
    double liczba;
    ifstream we (_nazwapliku.c_str());
    if (we.is_open()){
        we >> liczba;
        wiersze=liczba;
        we >> liczba;
        kolumny=liczba;
        zawartosc=new double *[wiersze];
        for (int i=0; i<wiersze; i++)
            zawartosc[i]=new double [kolumny];
        for (int i=0; i<wiersze; i++)
            for (int j=0; j<kolumny; j++){
                we >> liczba;
                zawartosc[i][j]=liczba;
            }
    }
    else{
        cout << "brak pliku o podanej nazwie";
        we.close();
        exit (1);
    }
    we.close();
}

double Macierz::policz_wyznacznik (int rozmiar){
  int p, h, k, i, j;
  double det=0;
  Macierz temp(rozmiar,rozmiar);

  if(rozmiar==1) {
    return zawartosc[0][0];
  } else if(rozmiar==2) {
    det=(zawartosc[0][0]*zawartosc[1][1]-zawartosc[0][1]*zawartosc[1][0]);
    return det;
  } else {
    for(p=0;p<rozmiar;p++) {
      h = 0;
      k = 0;
      for(i=1;i<rozmiar;i++) {
        for( j=0;j<rozmiar;j++) {
          if(j==p) {
            continue;
          }
          temp.zawartosc[h][k] = zawartosc[i][j];
          k++;
          if(k==rozmiar-1) {
            h++;
            k = 0;
          }
        }
      }
      det=det+zawartosc[0][p]*pow(-1,p)*temp.policz_wyznacznik(rozmiar-1);
    }

    return det;
  }
}

Macierz Macierz::odwrotna(){
    Macierz temp(wiersze-1, kolumny -1);
    Macierz wynik(wiersze, kolumny);
    for (int i=0; i<wiersze; i++){
        for (int j=0; j<kolumny; j++){
            for (int k=0; k<i; k++)
                for (int l=0; l<j; l++)
                    temp.zawartosc[k][l]=zawartosc[k][l];
            for (int k=i+1; k<wiersze; k++)
                for (int l=0; l<j; l++)
                    temp.zawartosc[k-1][l]=zawartosc[k][l];
            for (int k=0; k<i; k++)
                for (int l=j+1; l<kolumny; l++)
                    temp.zawartosc[k][l-1]=zawartosc[k][l];
            for (int k=i+1; k<kolumny; k++)
                for (int l=j+1; l<wiersze; l++)
                    temp.zawartosc[k-1][l-1]=zawartosc[k][l];
            if ((j+i)%2==0)
                wynik.zawartosc[i][j]=temp.policz_wyznacznik(wiersze-1);
            else
                wynik.zawartosc[i][j]=temp.policz_wyznacznik(wiersze-1)*(-1);
        }
    }
    double schowek;
    for (int i=0; i<wynik.wiersze; i++)
        for (int j=i+1; j<wynik.kolumny; j++){
            schowek=wynik.zawartosc[i][j];
            wynik.zawartosc[i][j]=wynik.zawartosc[j][i];
            wynik.zawartosc[j][i]=schowek;
        }
    double mnoznik=1/policz_wyznacznik(wynik.wiersze);
    for (int i=0; i<wynik.wiersze; i++)
        for (int j=0; j<wynik.kolumny; j++)
            wynik.zawartosc[i][j]=mnoznik*wynik.zawartosc[i][j];

    return wynik;
}

Macierz & Macierz::operator=(const Macierz &wzor) {
    for (int i=0; i<wiersze; i++)
        delete []zawartosc[i];
    delete []zawartosc;

    wiersze = wzor.wiersze;
    kolumny = wzor.kolumny;
    zawartosc=new double *[wiersze];
    for (int i=0; i<wiersze; i++)
        zawartosc[i]=new double [kolumny];
    for (int i=0; i<wiersze; i++)
        for (int j=0; j<kolumny; j++)
            zawartosc[i][j]=wzor.zawartosc[i][j];
    return *this;
}

Macierz operator+ (Macierz &x, Macierz &y){
    Macierz wynik (x.wiersze, x.kolumny);
    for (int i=0; i<x.wiersze; i++)
        for (int j=0; j<x.kolumny; j++)
            wynik.zawartosc[i][j]=x.zawartosc[i][j]+y.zawartosc[i][j];
    return wynik;
}


Macierz operator- (Macierz &x, Macierz &y){
    Macierz wynik (x.wiersze, x.kolumny);
    for (int i=0; i<x.wiersze; i++)
        for (int j=0; j<x.kolumny; j++)
            wynik.zawartosc[i][j]=x.zawartosc[i][j]-y.zawartosc[i][j];
    return wynik;
}

Macierz operator* (Macierz &x, Macierz &y){
    Macierz wynik (x.wiersze, y.kolumny);
    double liczba=0;
    for (int i=0; i<x.wiersze; i++){
        for (int j=0; j<y.kolumny; j++){
            for (int k=0; k<x.kolumny; k++)
                liczba=liczba+(x.zawartosc[i][k]*y.zawartosc[k][j]);
            wynik.zawartosc[i][j]=liczba;
            liczba=0;
        }
    }
    return wynik;
}

Macierz operator/ (Macierz &x, Macierz &y){
    Macierz wynik (x.wiersze, x.kolumny);
    Macierz mnoznik (y.wiersze, y.kolumny);
    mnoznik=y.odwrotna();
    wynik=x*mnoznik;
    return wynik;
}

void Macierz:: wydrukuj (){
    for (int i=0; i<wiersze; i++){
        for (int j=0; j<kolumny; j++)
            cout << zawartosc[i][j] << " ";
        cout <<endl;
    }
    cout << endl;
}

void Macierz:: zapisz(string nazwapliku){
    ofstream wy (nazwapliku.c_str());
    for (int i=0; i<wiersze; i++){
        for (int j=0; j<kolumny; j++)
            wy << zawartosc[i][j] << " ";
        wy << endl;
    }
    wy.close();
}
