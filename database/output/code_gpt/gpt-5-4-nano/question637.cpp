/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, N, C;
    while (cin >> P >> N >> C) {
        if (P == 0 && N == 0 && C == 0) break;

        vector<int> run(P, 0);
        long long ans = 0;

        for (int t = 0; t < N; t++) {
            for (int i = 0; i < P; i++) {
                int x;
                cin >> x;
                if (x == 1) {
                    run[i]++;
                } else {
                    if (run[i] >= C) ans++;
                    run[i] = 0;
                }
            }
        }

        for (int i = 0; i < P; i++) {
            if (run[i] >= C) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}