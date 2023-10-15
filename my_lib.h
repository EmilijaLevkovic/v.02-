#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <random>
#include <cstdlib>
#include <fstream>
#pragma once
#include <numeric>
#include <valarray>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <iterator>
#include <ctime>
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::microseconds;

struct studentas {
  string Vardas,Pavarde;
  vector <int> ND_Pazymis;
  int Egzaminas;
  double GalutinisVid;
  double GalutinisMed;
  string Vertinimas;
};

int nuskaitymas();
double mediana(vector<int> vekt);
float vidurkis(vector<int> vekt);
vector <int> random(int n);
bool pagalvarda(const studentas& a, const studentas& b);
void generatorius(int x, string pavadinimas);
void skirstymas(string pavadinimas, string naujas1, string naujas2);
