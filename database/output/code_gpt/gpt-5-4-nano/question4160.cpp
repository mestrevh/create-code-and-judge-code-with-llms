/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        total += x;
    }

    vector<long long> fact;
    fact.push_back(1);
    for (int i = 1; i <= 20; i++) {
        __int128 next = (__int128)fact.back() * i;
        if (next > (__int128)LLONG_MAX) break;
        fact.push_back((long long)next);
    }

    int best_k = 0;
    long long best_diff = llabs(fact[0] - total);

    for (int k = 1; k < (int)fact.size(); k++) {
        long long diff = llabs(fact[k] - total);
        if (diff < best_diff) {
            best_diff = diff;
            best_k = k;
        }
    }

    cout << "Bia arrecadou " << best_k << "! dinheiros e pode jogar tenis!";
    return 0;
}