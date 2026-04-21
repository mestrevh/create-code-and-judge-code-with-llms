/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double v;
    if (!(cin >> v)) return 0;

    vector<pair<double,int>> data;
    double d;
    int w;
    while (cin >> d >> w) data.push_back({d, w});

    double totalDist = 0.0;
    bool possible = true;
    for (auto &p : data) {
        totalDist += p.first;
        if (p.second == 0) possible = false;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    if (!possible) {
        cout << "Nao vai ter como completar o percurso, RIP.";
    } else {
        double t = totalDist / v;
        cout << "O percurso sera completado em " << t << " segundos!";
    }
    return 0;
}