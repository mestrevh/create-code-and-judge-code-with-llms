/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int idG = 0, idM = 0;
    double wG = -numeric_limits<double>::infinity();
    double wM = numeric_limits<double>::infinity();

    for (int i = 0; i < n; i++) {
        int id;
        double w;
        cin >> id >> w;
        if (w > wG) {
            wG = w;
            idG = id;
        }
        if (w < wM) {
            wM = w;
            idM = id;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Gordo: id: " << idG << " peso: " << wG << "Kg\n";
    cout << "Magro: id: " << idM << " peso: " << wM << "Kg\n";

    return 0;
}