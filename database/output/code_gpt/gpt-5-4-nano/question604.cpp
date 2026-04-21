/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long C;
    int N;
    if (!(cin >> C >> N)) return 0;

    vector<long long> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    long long step = C / N;

    bool ok = true;
    for (int i = 0; i < N; i++) {
        long long expected = (X[0] + i * step) % C;
        if (expected != X[i]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? 'S' : 'N');
    return 0;
}