/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; tc++) {
        long long N;
        cin >> N;

        cout << "caso " << tc << ":";
        long long start = N * N - N + 1;
        for (long long i = 0; i < N; i++) {
            long long x = start + 2 * i;
            cout << ' ' << x;
        }
        cout << "\n";
    }
    return 0;
}