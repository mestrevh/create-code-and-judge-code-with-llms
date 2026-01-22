/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Vila {
    string nome;
    int x, y, z;
    double distancia;

    void calcularDistancia(int px, int py, int pz) {
        distancia = sqrt(pow(px - x, 2) + pow(py - y, 2) + pow(pz - z, 2));
    }
};

bool comparator(const Vila &a, const Vila &b) {
    if (a.distancia != b.distancia)
        return a.distancia < b.distancia;
    return a.nome < b.nome;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    vector<Vila> vilas = {
        {"Solitude", 140, 200, 456},
        {"Kakariko", 0, 64, 10},
        {"Hogsmeade", 34, 110, 220}
    };

    for (auto &vila : vilas) {
        vila.calcularDistancia(x, y, z);
    }

    sort(vilas.begin(), vilas.end(), comparator);

    cout << vilas[0].nome << " " << vilas[1].nome << " " << vilas[2].nome << endl;

    return 0;
}
