/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static void ajudearachel(float troco) {
    long long cents = llround((double)troco * 100.0);

    vector<pair<int,long long>> notes = {
        {5000, 0}, {2000, 0}, {1000, 0}, {500, 0}, {200, 0}
    };

    vector<int> noteVals = {5000, 2000, 1000, 500, 200};
    vector<int> coinVals = {100, 50, 25, 10, 5};

    vector<long long> noteCount(noteVals.size(), 0), coinCount(coinVals.size(), 0);

    long long remaining = cents;

    for (size_t i = 0; i < noteVals.size(); i++) {
        noteCount[i] = remaining / noteVals[i];
        remaining %= noteVals[i];
    }

    for (size_t i = 0; i < coinVals.size(); i++) {
        coinCount[i] = remaining / coinVals[i];
        remaining %= coinVals[i];
    }

    long long x = 0, y = 0;
    for (auto v : noteCount) x += v;
    for (auto v : coinCount) y += v;

    cout << fixed << setprecision(2) << ((double)cents / 100.0) << "\n";
    cout << x << " notas e " << y << " moedas\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float pedido, pago;
    if (!(cin >> pedido)) return 0;
    cin >> pago;

    float troco = pago - pedido;
    if (troco < 0) troco = 0;

    ajudearachel(troco);
    return 0;
}