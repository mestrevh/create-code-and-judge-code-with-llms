/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double N;
    if (!(cin >> N)) return 0;

    long long cents = llround(N * 100.0L);

    vector<pair<long long, string>> items = {
        {10000, "R$ 100.00"},
        {5000, "R$ 50.00"},
        {2000, "R$ 20.00"},
        {1000, "R$ 10.00"},
        {500, "R$ 5.00"},
        {200, "R$ 2.00"},
        {100, "R$ 1.00"},
        {50, "R$ 0.50"},
        {25, "R$ 0.25"},
        {10, "R$ 0.10"},
        {5, "R$ 0.05"},
        {1, "R$ 0.01"}
    };

    for (auto &it : items) {
        long long value = it.first;
        string label = it.second;
        if (cents >= value) {
            long long cnt = cents / value;
            cents %= value;
            cout << cnt << (label.find("2.00") != string::npos || label.find("5.00") != string::npos || label.find("10.00") != string::npos || label.find("20.00") != string::npos || label.find("50.00") != string::npos || label.find("100.00") != string::npos ? " nota(s) de " : " moeda(s) de ");
            cout << label << "\n";
        }
    }

    return 0;
}