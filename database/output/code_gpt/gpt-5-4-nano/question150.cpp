/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H;
    if (!(cin >> H)) return 0;
    int n = (1 << H) - 1;
    vector<long long> V(n + 1);
    for (int i = 1; i <= n; i++) cin >> V[i];

    vector<long long> P(n + 1, 0);

    for (int i = n; i >= 1; i--) {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left > n) {
            P[i] = V[i];
        } else {
            P[i] = max(V[i] * P[left], V[i] * P[right]);
        }
    }

    cout << P[1] << "\n";
    return 0;
}