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
    vector<long long> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    const long long GAP = 10;
    long long total = 0;
    long long start = T[0];
    long long last = T[0];

    for (int i = 1; i < N; i++) {
        if (T[i] - last > GAP) {
            total += (last - start) + GAP + 1;
            start = T[i];
        }
        last = T[i];
    }
    total += (last - start) + GAP + 1;

    cout << total << "\n";
    return 0;
}