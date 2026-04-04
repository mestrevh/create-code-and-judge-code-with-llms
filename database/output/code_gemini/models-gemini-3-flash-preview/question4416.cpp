/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct Car {
    string name;
    double velocity;
    int original_index;
};

bool compareCars(const Car& a, const Car& b) {
    if (abs(a.velocity - b.velocity) > 1e-7) {
        return a.velocity > b.velocity;
    }
    return a.original_index < b.original_index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int limit;
    double distance;
    if (!(cin >> limit >> distance)) return 0;

    double times[3];
    string names[3] = {"Kwid Laranja", "Tesla Branco", "Gol Bolinha"};
    int min_v = limit / 2;
    int max_v = limit;

    vector<Car> validCars;
    for (int i = 0; i < 3; ++i) {
        if (cin >> times[i]) {
            double v = distance / times[i];
            if (v >= (double)min_v && v <= (double)max_v) {
                validCars.push_back({names[i], v, i});
            }
        }
    }

    if (validCars.empty()) {
        cout << "Infelizmente Xupenio nao podera ir ao evento mais importante do ano" << endl;
    } else {
        sort(validCars.begin(), validCars.end(), compareCars);
        for (const auto& car : validCars) {
            cout << "Xupenio pode utilizar o carro " << car.name 
                 << ", cuja velocidade no percurso eh " << fixed << setprecision(2) << car.velocity << endl;
        }
    }

    return 0;
}