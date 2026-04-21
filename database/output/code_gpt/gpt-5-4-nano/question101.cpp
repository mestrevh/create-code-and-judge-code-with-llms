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
    while ( (cin >> N) ) {
        if (N == 0) break;
        vector<long long> x(N), y(N);
        for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

        bool aligned = true;
        __int128 dx = x[1] - x[0];
        __int128 dy = y[1] - y[0];

        for (int i = 2; i < N && aligned; i++) {
            __int128 ex = x[i] - x[0];
            __int128 ey = y[i] - y[0];
            if (dx * ey != dy * ex) aligned = false;
        }

        cout << (aligned ? "ALINHADOS" : "NAO_ALINHADOS") << "\n";
    }
    return 0;
}