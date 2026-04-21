/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int popcount_int(int x) {
    return __builtin_popcount((unsigned)x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        vector<int> bits;
        bits.reserve(N);
        for (int x : a) bits.push_back(popcount_int(x));
        sort(bits.begin(), bits.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < K; i++) ans += bits[i];
        cout << ans << "\n";
    }
    return 0;
}