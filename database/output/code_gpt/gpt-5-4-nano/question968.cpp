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

    vector<long long> val(N);
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i] >> L[i] >> R[i];
    }

    long long S;
    cin >> S;

    function<bool(int, long long)> dfs = [&](int u, long long sum) -> bool {
        if (u == -1) return false;
        sum += val[u];
        if (L[u] == -1 && R[u] == -1) return sum == S;
        return (L[u] != -1 && dfs(L[u], sum)) || (R[u] != -1 && dfs(R[u], sum));
    };

    cout << (dfs(0, 0) ? "SIM" : "NAO");
    return 0;
}