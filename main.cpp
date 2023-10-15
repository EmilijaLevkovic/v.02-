#include "my_lib.h"

float vidurkis(vector<int> vekt)
{
  size_t size = vekt.size();

  if (size == 0)
  {
    return 0;
  }
  else
  {
    return static_cast<float>(accumulate(vekt.begin(), vekt.end(), 0)) / size;
  }

}
double mediana(vector<int> vekt)
{
  size_t size = vekt.size();

  if (size == 0)
  {
    return 0;
  }
  else
  {
    sort(vekt.begin(), vekt.end());
    if (size % 2 == 0)
    {
      return static_cast<float>(vekt[((size / 2) -1)] + vekt[size / 2]) / 2;
    }
    else
    {
      return vekt[size / 2];
    }
  }
}

vector <int> random(int n)
{
  random_device rnd_device;
  mt19937 mersenne_engine{ rnd_device() };
  uniform_int_distribution<int> dist{ 1, 10 };
  auto gen = [&dist, &mersenne_engine]() {
    return dist(mersenne_engine);
    };
  vector<int> vec(n);
  generate(begin(vec), end(vec), gen);
  return vec;
}

bool pagalvarda(const studentas& a, const studentas& b) {
  return a.Vardas< b.Vardas;
}


int main() {
  generatorius(10000, "studentai10000.txt");
  skirstymas("studentai10000.txt", "galvociai10000.txt", "vargsiukai10000.txt");
  generatorius(100000, "studentai100000.txt");
  skirstymas("studentai100000.txt", "galvociai100000.txt", "vargsiukai100000.txt");
  generatorius(1000000, "studentai1000000.txt");
  skirstymas("studentai1000000.txt", "galvociai1000000.txt", "vargsiukai1000000.txt");
}
