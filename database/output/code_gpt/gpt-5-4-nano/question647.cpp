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
        vector<long long> P(N);
        for (int i = 0; i < N; i++) cin >> P[i];

        long long ans = 0;
        long long offset = 0;
        for (int i = 0; i < N; i++) {
            long long pos = P[i] + offset;
            ans += pos;
            offset += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}