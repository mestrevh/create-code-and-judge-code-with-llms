/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int max_speed;
    double distance;
    double times[3];
    cin >> max_speed >> distance;
    for (int i = 0; i < 3; i++) {
        cin >> times[i];
    }

    vector<pair<double, int>> valid_cars;
    double speeds[3];

    speeds[0] = distance / times[0];
    if (speeds[0] <= max_speed && speeds[0] >= max_speed / 2.0) {
        valid_cars.push_back({speeds[0], 0});
    }

    speeds[1] = distance / times[1];
    if (speeds[1] <= max_speed && speeds[1] >= max_speed / 2.0) {
        valid_cars.push_back({speeds[1], 1});
    }

    speeds[2] = distance / times[2];
    if (speeds[2] <= max_speed && speeds[2] >= max_speed / 2.0) {
        valid_cars.push_back({speeds[2], 2});
    }

    sort(valid_cars.rbegin(), valid_cars.rend());

    if (valid_cars.empty()) {
        cout << "Infelizmente Xupenio nao podera ir ao evento mais importante do ano" << endl;
    } else {
        for (auto car : valid_cars) {
            string car_name;
            if (car.second == 0) {
                car_name = "Kwid Laranja";
            } else if (car.second == 1) {
                car_name = "Tesla Branco";
            } else {
                car_name = "Gol Bolinha";
            }
            cout << "Xupenio pode utilizar o carro " << car_name << ", cuja velocidade no percurso eh " << fixed << setprecision(2) << car.first << endl;
        }
    }

    return 0;
}
