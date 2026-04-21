/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double M;
    if (!(cin >> M)) return 0;

    vector<string> cor = {"Verde", "Vermelho", "Azul", "Amarelo"};
    vector<long double> P(4), V(4);
    long double bestRatio = -1;
    int bestIdx = -1;

    for (int i = 0; i < 4; i++) {
        long double p, v;
        cin >> p >> v;
        P[i] = p;
        V[i] = v;
        if (p <= M) {
            long double ratio = v / p;
            if (ratio > bestRatio + 1e-18L) {
                bestRatio = ratio;
                bestIdx = i;
            }
        }
    }

    if (bestIdx == -1) {
        cout << "Acho que vou a pé :( ";
        return 0;
    }

    if (bestIdx != 0 && P[0] <= M) {
        long double ratioVerde = V[0] / P[0];
        if (fabsl(ratioVerde - bestRatio) <= 1.0L) {
            cout << "Verde";
            return 0;
        }
    }

    cout << cor[bestIdx];
    return 0;
}