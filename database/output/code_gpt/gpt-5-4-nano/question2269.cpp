/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long V;
    int D;
    if (!(cin >> V)) return 0;
    cin >> D;

    long long totalCost = 0;
    long long totalTins = 0;

    for (int i = 0; i < D; i++) {
        long long T;
        cin >> T;
        if (T > 0) totalTins += T;

        for (long long j = 0; j < T; j++) {
            long long costPerBowl = 10;
            if (T == 1) costPerBowl = 10;
            else if (T >= 2 && T <= 10) costPerBowl = 10 - 1;
            else costPerBowl = 10 - 2;
            totalCost += costPerBowl;
        }
    }

    if (totalTins == 0) {
        cout << "Naruto nao apareceu para comer";
        return 0;
    }

    if (V >= totalCost) {
        cout << "Naruto conseguiu pagar a sua conta!";
    } else {
        cout << "Naruto, faltam " << (totalCost - V) << " ryos!";
    }
    return 0;
}