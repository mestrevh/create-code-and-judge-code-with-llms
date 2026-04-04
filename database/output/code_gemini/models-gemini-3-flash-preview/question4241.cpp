/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Car {
    string name;
    double weighted_sum;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy); 

    vector<Car> fleet;
    fleet.reserve(n);
    double total_weighted_sum = 0.0;

    for (int i = 0; i < n; ++i) {
        string model;
        while (getline(cin, model) && model.empty());
        if (model.empty()) break;

        double motor, suspension, turbo;
        if (!(cin >> motor >> suspension >> turbo)) {
            fleet.push_back({model, 0.0});
            continue;
        }
        getline(cin, dummy); 

        double current_weighted_sum = (motor * 5.0 + suspension * 2.0 + turbo * 3.0);
        fleet.push_back({model, current_weighted_sum});
        total_weighted_sum += current_weighted_sum;
    }

    if (!fleet.empty()) {
        double average_weighted_sum = total_weighted_sum / (double)fleet.size();
        for (const auto& car : fleet) {
            if (car.weighted_sum >= average_weighted_sum - 1e-9) {
                cout << car.name << "\n";
            }
        }
    }

    return 0;
}