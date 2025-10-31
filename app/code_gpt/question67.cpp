/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<pair<double, double>> points;
    double x, y;

    while (cin >> x >> y) {
        points.emplace_back(x, y);
    }

    // Definindo os limites do polígono (quadrado)
    double left = -2, right = 2, bottom = -3, top = 3;

    for (const auto& point : points) {
        if (point.first > left && point.first < right && point.second > bottom && point.second < top) {
            cout << "INTERIOR" << endl;
        } else {
            cout << "EXTERIOR" << endl;
        }
    }

    return 0;
}
