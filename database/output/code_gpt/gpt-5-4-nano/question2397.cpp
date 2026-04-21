/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    unordered_map<int, int> priceCents = {
        {1001, 150},
        {1002, 250},
        {1003, 350},
        {1004, 450},
        {1005, 550}
    };

    long long totalCents = 0;
    for (int i = 0; i < N; i++) {
        int C, Q;
        cin >> C >> Q;
        totalCents += 1LL * priceCents[C] * Q;
    }

    cout << fixed << setprecision(2) << (totalCents / 100.0) << "\n";
    return 0;
}