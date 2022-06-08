#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "Grafy.h"

using namespace std;
/*
 * Metoda tworzaca pusty graf w oparciu o
 * ilosc wierzcholkow, krawedzi, a takze ustalajaca który wierzcholek jest pierwszy
*/
Graf::Graf(int ilosc_wierzcholkow, int ilosc_krawedzi, int wierzcholek_poczatkowy)
{
	this->ilosc_wierzcholkow=ilosc_wierzcholkow;
	this->ilosc_krawedzi=ilosc_krawedzi;
	this->wierzcholek_poczatkowy=wierzcholek_poczatkowy;
	MacierzGrafu=new int*[ilosc_wierzcholkow];
	for (int i=0; i<ilosc_wierzcholkow; i++)
		MacierzGrafu[i]=new int[ilosc_wierzcholkow];
	for (int i=0; i<ilosc_wierzcholkow; i++)
		for (int j=0; j<ilosc_wierzcholkow; j++)
			MacierzGrafu[i][j]=0;

	Lista=new Element*[ilosc_wierzcholkow];

	for (int i=0; i<ilosc_wierzcholkow; i++)
		Lista[i]=NULL;


	
}



/*
* Funkcja wyszukujaca wierzcholek o 
* najmniejszym koszcie dotarcia
*/
int Graf::Minimum(wartosci* tab) {
	int min=-1;
	int obecny=nieskonczonosc;
	for (int i=0;i<ilosc_wierzcholkow; i++) {
		if (!tab[i].przetworzony && tab[i].odleglosc < obecny) {
			min=i;
			obecny=tab[i].odleglosc;
		}
	}
	return min;
}
/*
* Funkcja realizujaca algorytm Dijkstry dla
* reprezentacji grafu za pomoc� listy
*/
wartosci* Graf::Dijkstra_Lista() {

	wartosci* tab=new wartosci[ilosc_wierzcholkow];
	droga=new int[ilosc_wierzcholkow];
	Element *pomocniczy;
	for (int i=0; i<ilosc_wierzcholkow; i++) {
		if (i==wierzcholek_poczatkowy)
		{
			tab[i].odleglosc=0;
		}
		else
		{
			tab[i].odleglosc=nieskonczonosc;
		}
		tab[i].przetworzony=false;
		droga[i]=-1;
	}

	int min = Minimum(tab);

	while (min!=-1) {
		tab[min].przetworzony=true;
		pomocniczy=Lista[min];
		
		for (pomocniczy=Lista[min]; pomocniczy; pomocniczy=pomocniczy->kolejny)
		{
			if (tab[min].odleglosc+pomocniczy->waga<tab[pomocniczy->wezel].odleglosc) {
				tab[pomocniczy->wezel].odleglosc=tab[min].odleglosc+pomocniczy->waga;
				droga[pomocniczy->wezel]=min;
			}
			
		}
		
		min=Minimum(tab);

	}
	return tab;
}


/*
* Funkcja realizujaca algorytm Dijkstry dla
* reprezentacji grafu za pomoca macierzy
*/

wartosci* Graf::Dijkstra_Macierz() {

	wartosci* tab=new wartosci[ilosc_wierzcholkow];
	droga=new int[ilosc_wierzcholkow];
	for (int i=0; i<ilosc_wierzcholkow; i++) {
		if (i==wierzcholek_poczatkowy)
		{
			tab[i].odleglosc=0;
		}
		else
		{
			tab[i].odleglosc=nieskonczonosc;
		}
		tab[i].przetworzony=false;
		droga[i]=-1;
	}

	int min = Minimum(tab);
	while (min!=-1) {
		tab[min].przetworzony = true;
		for (int i=0; i<ilosc_wierzcholkow; i++) {
			if (MacierzGrafu[min][i]>0 && tab[min].odleglosc+MacierzGrafu[min][i]<tab[i].odleglosc) {
				tab[i].odleglosc=tab[min].odleglosc+MacierzGrafu[min][i];
				droga[i]=min;
			}
		}
		
		min=Minimum(tab);
	}

	return tab;
}

int Graf::dodawanie_krawedzi(int i, int j, int waga)
{
	
	element=new Element;
	element->wezel=j;
	element->waga=waga;
	element->kolejny=Lista[i];
	Lista[i]=element;

	return MacierzGrafu[i][j]=waga;

	

}
/*
funkcja wyswietlajaca graf
dla reprezentacji macierzy*/

void Graf::wyswietl_macierz()
{
	for (int i=0; i<ilosc_wierzcholkow; i++)
	{
		for (int j=0; j<ilosc_wierzcholkow; j++)
		{
			std::cout << MacierzGrafu[i][j] << "\t";
		}
		std::cout << endl;
	}
}
/*
funkcja wyswietlajaca graf 
dla reprezentacji listy*/
void Graf::wyswietl_liste()
{
	Element *tmp;
	for (int i=0; i<ilosc_wierzcholkow; i++)
	{
		tmp=Lista[i];
		cout<<i<< ":";
		while (tmp)
		{
			cout<<tmp->wezel<<" waga :"<< tmp->waga<<" ";
			tmp=tmp->kolejny;
		}
		cout<<endl;
	}
}
/*
Funkcja zapisujaca w pliku Wyniki.txt
najkrotsza sciezke do poszczegolnych elementow*/

void Graf::zapisz( wartosci *tab) {
	int licznik=0;
	int *Tab_drogi=new int[ilosc_wierzcholkow];       
	ofstream plik;
	plik.open("Sciezka.txt");
	for (int i=0; i<ilosc_wierzcholkow; i++)
	{
		plik<<i<<":" ;
		for (int j=i; j>-1; j=droga[j])
			Tab_drogi[licznik++]=j;
		while (licznik)
		plik<<Tab_drogi[--licznik]<<"->";
		plik<<"( "<<tab[i].odleglosc<< ") "<<endl;
	}
	plik.close();
}

/*destruktor*/
Graf::~Graf()
{
}
