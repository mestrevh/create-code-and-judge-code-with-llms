/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    while ( (cin >> T >> N) ) {
        if (T == 0 && N == 0) break;

        vector<long long> pts(T);
        for (int i = 0; i < T; i++) {
            string name;
            cin >> name >> pts[i];
        }

        long long bestX = -1, bestD = -1;
        long long totalGoalsPoints = N * 3;

        for (int i = 0; i < T; i++) {
            long long pi = pts[i];
            if (pi % 2 != 0) continue;
            long long x = pi / 2;
            if (x < 0) continue;
            long long d = totalGoalsPoints - x * 2;
            if (d < 0) continue;
            if (bestX == -1 || d > bestD) {
                bestX = x;
                bestD = d;
            }
        }

        if (bestX == -1) {
            long long ans = 0;
            cout << ans << "\n";
            continue;
        }

        long long x = bestX;
        long long D = bestD;

        long long k = D / T;
        long long r = D % T;

        long long ties = r;
        cout << ties << "\n";
    }

    return 0;
}