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
    if (!(cin >> N)) return 0;

    long long totalCents = llround(N * 100.0);

    vector<pair<long long, string>> notes = {
        {10000, "100.00"},
        {5000, "50.00"},
        {2000, "20.00"},
        {1000, "10.00"},
        {500, "5.00"},
        {200, "2.00"}
    };

    vector<pair<long long, string>> coins = {
        {100, "1.00"},
        {50, "0.50"},
        {25, "0.25"},
        {10, "0.10"},
        {5, "0.05"},
        {1, "0.01"}
    };

    cout << "NOTAS:\n";
    for (auto &p : notes) {
        long long val = p.first;
        long long cnt = totalCents / val;
        totalCents %= val;
        cout << cnt << " nota(s) de R$ " << p.second << "\n";
    }

    cout << "MOEDAS:\n";
    for (auto &p : coins) {
        long long val = p.first;
        long long cnt = totalCents / val;
        totalCents %= val;
        cout << cnt << " moeda(s) de R$ " << p.second << "\n";
    }

    return 0;
}