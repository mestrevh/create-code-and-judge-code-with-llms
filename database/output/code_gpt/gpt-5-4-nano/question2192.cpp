/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D, R, L, P, G;
    if (!(cin >> D >> R >> L >> P >> G)) return 0;

    long long distSegment = D / (P + 1);
    if (distSegment * (P + 1) != D) {
        cout << "Nao pode viajar.\n";
        return 0;
    }

    long long capacityLiters = L;
    long long costPerLiter = G;

    long long fuel = capacityLiters;
    long long money = R;

    long long neededLitersPerSegment = (distSegment + 9) / 10;

    for (int i = 0; i < P; i++) {
        if (fuel < neededLitersPerSegment) {
            long long buy = capacityLiters - fuel;
            long long cost = buy * costPerLiter;
            if (cost > money) {
                cout << "Nao pode viajar.\n";
                return 0;
            }
            money -= cost;
            fuel = capacityLiters;
        }
        fuel -= neededLitersPerSegment;
    }

    long long finalSegment = distSegment;
    if (fuel < (finalSegment + 9) / 10) {
        cout << "Nao pode viajar.\n";
        return 0;
    }
    fuel -= (finalSegment + 9) / 10;

    cout << "Pode viajar.\n";
    cout << "R$: " << money << "\n";
    return 0;
}