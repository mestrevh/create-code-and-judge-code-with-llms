/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P;
    if (!(cin >> P)) return 0;

    vector<long long> coins = {500, 100, 50, 10, 5, 1};
    vector<long long> cnt(6, 0);

    for (int i = 0; i < 6; i++) {
        cnt[i] = P / coins[i];
        P %= coins[i];
    }

    cout << cnt[0] << " moedas de 500.\n";
    cout << cnt[1] << " moedas de 100.\n";
    cout << cnt[2] << " moedas de 50.\n";
    cout << cnt[3] << " moedas de 10.\n";
    cout << cnt[4] << " moedas de 5.\n";
    cout << cnt[5] << " moedas de 1.\n";

    return 0;
}