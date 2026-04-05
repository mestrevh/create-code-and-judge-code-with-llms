/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<long double> sum(N + 1, 0.0L);

    for (int i = 0; i < Q; i++) {
        int V;
        long double P;
        cin >> V >> P;
        sum[V] += P;
    }

    int bestM = 1;
    for (int v = 2; v <= N; v++) {
        if (sum[v] > sum[bestM]) bestM = v;
    }

    cout << bestM << ' ' << fixed << setprecision(1) << (double)sum[bestM];
    return 0;
}