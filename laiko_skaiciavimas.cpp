#include "my_lib.h"


void generatorius(int x, string pavadinimas) {
  srand(time(nullptr));
  ofstream file(pavadinimas);

  auto start = high_resolution_clock::now();

  for (int n = 1; n <= x; ++n) {
    file << "Vardas(" << n << ") Pavarde(" << n << ")";
    for (int i = 0; i < 8; ++i) {
      file << "  " << (rand() % 10 + 1);
    }
    file << "\n";
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);

  cout << "Failo sukurimo trukmė: "
    << duration.count() << " sekundžių" << endl;

  file.close();
}


void skirstymas(string pavadinimas, string naujas1, string naujas2) {
    ifstream inputfile(pavadinimas);
    ofstream outputfile1(naujas1);
    ofstream outputfile2(naujas2);
    vector<studentas> mokiniai;
    mokiniai.reserve(10000001);

    string line;

    auto start_total = high_resolution_clock::now(); 
    microseconds read_duration(0);
    microseconds calc_duration(0);
    microseconds write_duration(0);

    while (getline(inputfile, line)) {
        auto start_line_read = high_resolution_clock::now(); 
        istringstream iss(line);
        studentas Laikinas;
        iss >> Laikinas.Pavarde >> Laikinas.Vardas;
        int nd;
        vector<int> temp;
        while (iss >> nd) {
            temp.push_back(nd);
        }
        for (int i = 0; i < temp.size() - 1; i++) {
            Laikinas.ND_Pazymis.push_back(temp[i]);
        }
        Laikinas.Egzaminas = temp.back();
        auto end_line_read = high_resolution_clock::now(); 

        auto start_calc = high_resolution_clock::now(); 
        Laikinas.GalutinisMed = mediana(Laikinas.ND_Pazymis) * 0.4 + Laikinas.Egzaminas * 0.6;
        auto end_calc = high_resolution_clock::now(); 

        auto start_write = high_resolution_clock::now(); 
        if (Laikinas.GalutinisMed < 5) {
            Laikinas.Vertinimas = "blogai";
            outputfile2 << Laikinas.Pavarde << " " << Laikinas.Vardas<< " ";
            for (auto& paz : Laikinas.ND_Pazymis) {
                outputfile2 << paz << " ";
            }
            outputfile2 << Laikinas.Egzaminas << " " << Laikinas.Vertinimas << endl;
        }
        else {
            Laikinas.Vertinimas = "gerai";
            outputfile1 << Laikinas.Pavarde << " " << Laikinas.Vardas << " ";
            for (auto& paz : Laikinas.ND_Pazymis) {
                outputfile1 << paz << " ";
            }
            outputfile1 << Laikinas.Egzaminas << " " << Laikinas.Vertinimas << endl;
        }
        auto end_write = high_resolution_clock::now(); 

        mokiniai.push_back(move(Laikinas));

        read_duration += duration_cast<microseconds>(end_line_read - start_line_read);
        calc_duration += duration_cast<microseconds>(end_calc - start_calc);
        write_duration += duration_cast<microseconds>(end_write - start_write);
    }

    auto end_total = high_resolution_clock::now(); 

    cout << "Duomenų nuskaitimas iš failo užtruko: "
        << double(read_duration.count())/1000000
        << endl;
    cout << "Studentų rūšiavimas į dvi grupes užtruko: "
        << double(calc_duration.count())/1000000
        << endl;
    cout << "Studentų išvedimas į naujus failus užtruko: "
        << double(write_duration.count())/1000000
        << endl;
    cout << "Iš viso užtruko: "
        << double(duration_cast<std::chrono::microseconds>(end_total - start_total).count())/1000000
        <<"sek. 
        << endl;
}
