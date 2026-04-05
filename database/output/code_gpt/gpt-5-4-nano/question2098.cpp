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
    double T;
    if (!(cin >> N >> T)) return 0;

    vector<long long> house(N);
    for (int i = 0; i < N; i++) cin >> house[i];

    int idx = -1;
    for (int i = 0; i < N; i++) {
        double p;
        cin >> p;
        if (idx == -1) {
            if (fabs(p - T) < 1e-9) idx = i;
        }
    }

    if (idx == -1) {
        cout << "Nenhuma das jovens e a moca do baile.";
    } else {
        cout << "Cinderela mora na casa " << house[idx] << "!";
    }
    return 0;
}