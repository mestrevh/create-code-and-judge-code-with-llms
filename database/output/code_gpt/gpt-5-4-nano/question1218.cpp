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

    vector<double> total(N + 1, 0.0);
    for (int i = 0; i < Q; i++) {
        int V;
        double P;
        cin >> V >> P;
        total[V] += P;
    }

    int bestM = 1;
    double bestT = total[1];
    for (int v = 2; v <= N; v++) {
        if (total[v] > bestT) {
            bestT = total[v];
            bestM = v;
        }
    }

    cout << bestM << " " << fixed << setprecision(1) << bestT << "\n";
    return 0;
}