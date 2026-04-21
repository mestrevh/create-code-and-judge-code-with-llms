/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double vMax;
    long double dist;
    if (!(cin >> vMax >> dist)) return 0;

    long double a, b, c;
    cin >> a >> b >> c;

    long double vMin = floor((vMax / 2.0L));

    struct Car {
        string name;
        long double time;
    };

    vector<Car> cars = {
        {"Kwid Laranja", a},
        {"Tesla Branco", b},
        {"Gol Bolinha", c}
    };

    struct Result {
        long double speed;
        int idx;
        string name;
    };

    vector<Result> ok;
    for (int i = 0; i < 3; i++) {
        long double speed = dist / cars[i].time;
        if (speed <= vMax + 1e-12L && speed >= vMin - 1e-12L) {
            ok.push_back({speed, i, cars[i].name});
        }
    }

    auto fmt = [&](long double x) {
        ostringstream oss;
        oss.setf(ios::fixed);
        oss << setprecision(2) << (double)x;
        return oss.str();
    };

    if (ok.empty()) {
        cout << "Infelizmente Xupenio nao podera ir ao evento mais importante do ano";
        return 0;
    }

    stable_sort(ok.begin(), ok.end(), [&](const Result& r1, const Result& r2) {
        if (fabsl(r1.speed - r2.speed) > 1e-12L) return r1.speed > r2.speed;
        return r1.idx < r2.idx;
    });

    cout.setf(std::ios::fmtflags(0), std::ios::floatfield);
    for (auto &r : ok) {
        cout << "Xupenio pode utilizar o carro " << r.name
             << ", cuja velocidade no percurso eh " << fmt(r.speed) << "\n";
    }

    return 0;
}