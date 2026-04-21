/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    cout << N << "\n";

    vector<pair<long long, string>> notas = {
        {100, "R$ 100,00"},
        {50, "R$ 50,00"},
        {20, "R$ 20,00"},
        {10, "R$ 10,00"},
        {5, "R$ 5,00"},
        {2, "R$ 2,00"},
        {1, "R$ 1,00"}
    };

    long long restante = N;
    for (auto &p : notas) {
        long long val = p.first;
        long long q = restante / val;
        restante %= val;
        cout << q << " nota(s) de " << p.second << "\n";
    }
    return 0;
}