/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    if (!(cin >> N >> E)) return 0;

    vector<long long> pos(E), dir(E);
    for (int i = 0; i < E; i++) {
        long long V, D;
        cin >> V >> D;
        pos[i] = V - 1;
        dir[i] = D;
    }

    sort(pos.begin(), pos.end());
    vector<int> idx;
    idx.reserve(E);
    for (long long i = 0; i < E; i++) idx.push_back((int)i);

    long long L = 1;
    for (int i = 1; i < E; i++) {
        long long d = pos[i] - pos[i - 1];
        long long g = std::gcd(L, d);
        L = g;
    }
    long long dwrap = (pos[0] + N) - pos[E - 1];
    L = std::gcd(L, dwrap);

    long long ans;
    if (L == 0) ans = 0;
    else ans = N / L;

    cout << ans << "\n";
    return 0;
}