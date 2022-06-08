#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <climits>

#define nieskonczonosc INT_MAX

using namespace std;

struct wartosci{
    int odleglosc;
    bool przetworzony;
};

struct Element{

    Element* kolejny;
    int waga;
    int wezel;
};

class Graf{

    private:
    int *droga;
    int **MacierzGrafu;
    Element *element;
    Element **Lista;
    int ilosc_wierzcholkow;
    int ilosc_krawedzi;
    int wierzcholek_poczatkowy;
    public:
    Graf(){};
    Graf(int ilosc_wierzcholkow, int ilosc_krawedzi, int wierzcholek_poczatkowy);
    ~Graf();
    int dodawanie_krawedzi(int i, int j, int waga);
    void wyswietl_macierz();
    void wyswietl_liste();
    int Minimum(wartosci* tab);
    wartosci* Dijkstra_Macierz();
    wartosci* Dijkstra_Lista();
    void zapisz(wartosci *tab);

};