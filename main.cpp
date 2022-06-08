#include "Grafy.h"
#include "Funkcje.h"

int main(){
    char opcja;
    Graf* _Graf=NULL;
    fstream wartosci_wyniku;
    wartosci_wyniku.open("czasy.txt", ios::app);
    while(1)
    {
        cout<<"G - Wyswietl Graf" << endl;
        cout<<"W - Wczytaj " << endl;
        cout<<"D - test macierz" << endl;
        cout<<"L - test lista" << endl;
        cout<<"M - Dijkstra macierz" << endl;
        cout<<"C - Dijkstra lista" << endl;
        cout<<"Z - Zakoncz prace programu" << endl;
        cout<<"podaj opcje: "<<endl;
        cin>>opcja;

        switch(opcja)
        {
            case 'Z':
            cout<<"Program zakonczyl dzialanie"<<endl;
            return 0;
            break;
            case 'G':
            cout<<"Macierz: "<<endl;
            _Graf->wyswietl_macierz();
            cout<<"Lista"<<endl;
            _Graf->wyswietl_liste();
            break;
            case 'W':
            Wczytaj(_Graf);
            break;
            case 'D':
            test_macierz(_Graf, wartosci_wyniku);
            break;
            case 'L':
            test_lista(_Graf, wartosci_wyniku);
            break;
            case 'M':
            Macierz_czas(_Graf, wartosci_wyniku);
            break;
            case 'C':
            Lista_czas(_Graf, wartosci_wyniku);
            break;
        }
    }
    wartosci_wyniku.close();
}