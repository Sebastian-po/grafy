#pragma once
#include "Grafy.h"
#include <chrono>

using namespace std;

void Wczytaj(Graf *&_Graf);
void Zrob_graf();
void test_macierz(Graf*& _Graf, fstream& wartosci_wyniku);
void test_lista(Graf*& _Graf, fstream& wartosci_wyniku);
void Macierz_czas(Graf*& _Graf, fstream& czasy);
void Lista_czas(Graf*& _Graf, fstream& czasy);