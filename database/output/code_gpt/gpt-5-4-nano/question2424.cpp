/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double N;
    double X;
    if (!(cin >> N >> X)) return 0;

    if (N == 0) {
        cout << "Vamos pro posto Ipiranga ja!" << "\n";
        return 0;
    }

    double totalDist = 0.0;
    for (int i = 0; i < 4; i++) {
        string S;
        long long D;
        cin >> S >> D;
        totalDist += (double)D;
    }

    double maxDist = N * X;
    const double eps = 1e-9;

    if (maxDist + eps >= totalDist) {
        cout << "Tokyo e demais, temos que vir de novo!" << "\n";
    } else {
        cout << "Vamos de metro mesmo!" << "\n";
    }

    return 0;
}