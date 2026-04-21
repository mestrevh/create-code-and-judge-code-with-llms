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
    while (T--) {
        int N;
        long long X;
        cin >> N >> X;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        bool ok = false;
        long long sum = 0;
        int l = 0;
        for (int r = 0; r < N; r++) {
            sum += a[r];
            while (l <= r && sum > X) {
                sum -= a[l++];
            }
            if (sum == X) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}