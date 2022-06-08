#include "Funkcje.h"
#include <ctime>
#define MAX 20
#define ILOSC 10
using namespace std;



void Zrob_graf()
{
	int ilosc_krawedzi;
	int ilosc_wierzcholkow;
	int wierzcholek_poczatkowy;
	
	double gestosc;
	string nazwa_pliku;
	ofstream plik;
	int waga;
	
	
	for (int j=ILOSC; j<=MAX; j=j*10)
	{
		for (double i=0.25; i<=1; i=i+0.25)
		{
			int k=i*100;
			plik.open(to_string(k)+"%"+to_string(j)+".txt");
			ilosc_wierzcholkow=j;
			gestosc=i;
			wierzcholek_poczatkowy=0;
			ilosc_krawedzi=((ilosc_wierzcholkow*(ilosc_wierzcholkow-1))/2)*gestosc;

			plik<<ilosc_krawedzi<<" "<<ilosc_wierzcholkow<<" "<<wierzcholek_poczatkowy<<endl;
			int licznik_krawedzi=0;
			for (int i=0;i<ilosc_wierzcholkow;i++)
				for (int j=i;j<ilosc_wierzcholkow;j++)
				{
						
					if (i!=j && licznik_krawedzi<ilosc_krawedzi)
					{
						waga=rand()%40+1;
						plik<<i<<" "<<j<<" "<<waga<<endl;
						plik<<j<<" "<<i<<" "<<waga<<endl;
						licznik_krawedzi++;
					}
				}

			plik.close();
		}
	}
}



void Wczytaj(Graf *&_Graf)
{
	int ilosc_krawedzi;
	int ilosc_wierzcholkow;
	int wierzcholek_poczatkowy;
	int wierz_poccz;
	int wierz_kon;
	int waga;
	string nazwa_pliku;
	ifstream plik;
	printf("podaj nazwe pliku \n");
	cin>>nazwa_pliku;


	plik.open(nazwa_pliku.c_str());

	if (plik.good())
	{
		plik>>ilosc_krawedzi;
		plik>>ilosc_wierzcholkow;
		plik>>wierzcholek_poczatkowy;
		_Graf=new Graf(ilosc_wierzcholkow, ilosc_krawedzi, wierzcholek_poczatkowy);
		while (!plik.eof())
		{
			plik>>wierz_poccz;
			plik>>wierz_kon;
			plik>>waga;

			_Graf->dodawanie_krawedzi(wierz_poccz, wierz_kon, waga);
		}

	}
	else
	{
		printf("zla nazwa pliku \n");
	}
	plik.close();


}



void Macierz_czas(Graf*& _Graf, fstream& czasy) {
	
			double czas=0;
			auto t_start1 = std::chrono::high_resolution_clock::now();
            wartosci* tab=_Graf->Dijkstra_Macierz();
            auto t_end1 = std::chrono::high_resolution_clock::now(); 
            czas=std::chrono::duration<double, std::milli>(t_end1 - t_start1).count(); 
			_Graf->zapisz(tab);
			czasy<<"wczytany graf macierz-"<<czas<<"ms"<<endl;
}

void Lista_czas(Graf*& _Graf, fstream& czasy) {
	
			double czas=0;
			auto t_start1 = std::chrono::high_resolution_clock::now();
            wartosci* tab=_Graf->Dijkstra_Lista();
            auto t_end1 = std::chrono::high_resolution_clock::now(); 
            czas=std::chrono::duration<double, std::milli>(t_end1 - t_start1).count(); 
			_Graf->zapisz(tab);
			czasy<<"wczytany graf lista-"<<czas<<"ms"<<endl;
}

void test_macierz(Graf*& _Graf, fstream& czasy) {
	int ilosc_krawedzi;
	int ilosc_wierzcholkow;
	int wierzcholek_poczatkowy;
	int wierz_poccz;
	int wierz_kon;
	int waga;
	string nazwa_pliku;
	ifstream plik;
	

	for (int j=ILOSC; j<=MAX; j=j*10)
	{
		for (double i=0.25; i<=1; i=i+0.25)
		{
			double czas=0;
			for (int h=0; h<100; h++)
			{
			Zrob_graf();
			int k=i*100;
			plik.open(to_string(k)+"%"+to_string(j)+".txt");

			if (plik.good())
			{
				plik>>ilosc_krawedzi;
				plik>>ilosc_wierzcholkow;
				plik>>wierzcholek_poczatkowy;
				_Graf=new Graf(ilosc_wierzcholkow, ilosc_krawedzi, wierzcholek_poczatkowy);
				while (!plik.eof())
				{
				plik>>wierz_poccz;
				plik>>wierz_kon;
				plik>>waga;

				_Graf->dodawanie_krawedzi(wierz_poccz, wierz_kon, waga);
				}

			}
			else
			{
				printf("zla nazwa pliku \n");
			}
			plik.close();


			
			
			auto t_start1 = std::chrono::high_resolution_clock::now();
            wartosci* tab=_Graf->Dijkstra_Macierz();
            auto t_end1 = std::chrono::high_resolution_clock::now(); 
            czas+=std::chrono::duration<double, std::milli>(t_end1 - t_start1).count(); 
			_Graf->zapisz(tab);
			}
			int m=i*100;
			czasy<<to_string(m)+"%"+to_string(j)<<"-"<<czas<<"ms"<<endl;
		}
	}

}




void test_lista(Graf*& _Graf, fstream& czasy) {
	int ilosc_krawedzi;
	int ilosc_wierzcholkow;
	int wierzcholek_poczatkowy;
	int wierz_poccz;
	int wierz_kon;
	int waga;
	string nazwa_pliku;
	ifstream plik;
	for (int j=ILOSC; j<=MAX; j=j*10)
	{
		for (double i=0.25; i<=1; i=i+0.25)
		{
			double czas=0;
			for (int h=0; h<100; h++)
			{
			Zrob_graf();
			int k=i*100;
			plik.open(to_string(k)+"%"+to_string(j)+".txt");

			if (plik.good())
			{
				plik>>ilosc_krawedzi;
				plik>>ilosc_wierzcholkow;
				plik>>wierzcholek_poczatkowy;
				_Graf=new Graf(ilosc_wierzcholkow, ilosc_krawedzi, wierzcholek_poczatkowy);
				while (!plik.eof())
				{
					plik>>wierz_poccz;
					plik>>wierz_kon;
					plik>>waga;

					_Graf->dodawanie_krawedzi(wierz_poccz, wierz_kon, waga);
				}

			}
			else
			{
				printf("zla nazwa pliku \n");
			}
			plik.close();


			
			
			auto t_start2 = std::chrono::high_resolution_clock::now();
            wartosci* tab=_Graf->Dijkstra_Lista();
            auto t_end2 = std::chrono::high_resolution_clock::now(); 
            czas+=std::chrono::duration<double, std::milli>(t_end2 - t_start2).count(); 
			_Graf->zapisz(tab);
			}
			int m=i*100;
			czasy<<to_string(m)+"%"+to_string(j)<<"-"<<czas<<"ms"<<endl;
		}
	}

}
