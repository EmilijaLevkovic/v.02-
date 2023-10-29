
#include <algorithm>
#include <chrono> // Įtraukiame biblioteką, kuri leidžia matuoti laiką
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::seconds;
using namespace std;
// Struktūra, kuri saugo studento duomenis
struct Studentas {
  string vardas;
  string pavarde;
  vector<int> nd;   // Namų darbų pažymiai
  int egz;          // Egzamino pažymys
  double galutinis; // Galutinis balas
};

vector<Studentas> nuskaityti_duomenis(const string& failo_vardas);

pair<vector<Studentas>, vector<Studentas>> padalinti_studentus(const vector<Studentas>& studentai);

void surusiuoti_studentus(vector<Studentas>& studentai);

void isvesti_duomenis(const string& failo_vardas, const vector<Studentas>& studentai);
