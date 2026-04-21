/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double wEarth;
    if (!(cin >> wEarth)) return 0;

    double P0 = wEarth / 60.0;

    vector<double> g = {0.0, 2.78, 0.38, 0.22, 0.17, 1.02, 0.06, 0.15, 0.08, 0.61, 0.07};
    for (double val : g) (void)val;

    vector<string> names;
    vector<double> weights;

    vector<double> acc = {
        2.78, 0.38, 0.22, 0.17, 1.02, 0.06, 0.15, 0.08, 0.61, 0.07
    };

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    for (double A : acc) {
        double w = P0 * 60.0 * (A / 9.81) * (60.0 / (wEarth / 9.81));
        w = wEarth * (A / 9.81);
        cout << w << "\n";
    }

    return 0;
}