/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<double> result(N);
    for (int i = 0; i < N; i++) {
        int D;
        double P;
        cin >> D >> P;

        double pct = 0.0;
        if (D == 0) pct = 0.25;
        else if (D == 1) pct = 0.20;
        else if (D == 2) pct = 0.18;
        else if (D == 3) pct = 0.15;
        else if (D == 4) pct = 0.12;
        else pct = 0.10;

        double price = P;
        for (int year = 1; year <= 3; year++) {
            double decrease = pct * price;
            if (price <= 100.0 + 1e-9) decrease /= 2.0;
            price -= decrease;
            if (price < 45.0) price = 45.0;
        }
        result[i] = price;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);
    for (int i = 0; i < N; i++) {
        cout << "Jogo[" << i << "] = R$" << result[i] + 1e-9 << "\n";
    }
    return 0;
}