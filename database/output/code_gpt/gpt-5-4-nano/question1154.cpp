/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P, S, T;
    if (!(cin >> P >> S >> T)) return 0;
    vector<long long> a = {P, S, T};

    bool hasZero = false;
    for (auto x : a) if (x == 0) hasZero = true;

    bool okGreaterThanTen = false, okEven = false;
    for (auto x : a) {
        if (x == 0) continue;
        if (x > 10) okGreaterThanTen = true;
        if (x % 2 == 0) okEven = true;
    }

    if (!hasZero && okGreaterThanTen && okEven) cout << "Sim\n";
    else cout << "Não\n";

    return 0;
}