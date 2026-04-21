/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string ordinal(int idx) {
    if (idx == 0) return "Primeiro";
    if (idx == 1) return "Segundo";
    if (idx == 2) return "Terceiro";
    return "Quarto";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int monthNames[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    vector<string> monthStr = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};

    vector<array<double,8>> a(12);
    for (int m = 0; m < 12; m++) {
        for (int i = 0; i < 8; i++) {
            if (!(cin >> a[m][i])) return 0;
        }
    }

    double best = 1e18;
    int bestMonth = -1, bestK = -1, bestDay = -1;

    for (int m = 0; m < 12; m++) {
        for (int k = 0; k < 4; k++) {
            int satIndex = 2*k;
            int sunIndex = 2*k + 1;

            double ps = a[m][satIndex];
            if (ps <= 0.5) {
                if (m < bestMonth || bestMonth == -1) {
                    bestMonth = m; bestK = k; bestDay = 0;
                } else if (m == bestMonth) {
                    if (k < bestK) { bestK = k; bestDay = 0; }
                    else if (k == bestK && 0 < bestDay) bestDay = 0;
                }
            }

            double pd = a[m][sunIndex];
            if (pd <= 0.5) {
                if (m < bestMonth || bestMonth == -1) {
                    bestMonth = m; bestK = k; bestDay = 1;
                } else if (m == bestMonth) {
                    if (k < bestK) { bestK = k; bestDay = 1; }
                    else if (k == bestK && 1 < bestDay) bestDay = 1;
                }
            }
        }
    }

    if (bestMonth == -1) {
        cout << "Proximo ano eu tento denovo..." << "\n";
    } else {
        cout << "O melhor dia e no " << ordinal(bestK) << " " << (bestDay==0 ? "Sabado" : "Domingo") << " de " << monthStr[bestMonth] << "\n";
    }

    return 0;
}