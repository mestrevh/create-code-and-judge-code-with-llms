/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, L;
    while ( (cin >> N >> L) ) {
        if (N == 0 && L == 0) break;
        vector<long long> a(L);
        for (int i = 0; i < L; i++) cin >> a[i];

        if (N == 1) {
            cout << 0 << "\n";
            continue;
        }

        vector<long long> b(L);
        for (int i = 0; i < L; i++) b[i] = a[i] - i;

        unordered_map<long long, pair<int,int>> mp;
        mp.reserve(L * 2);

        int ans = INT_MAX;
        int i = 0;
        while (i < L) {
            int j = i;
            long long key = b[i];
            int mn = INT_MAX, mx = INT_MIN;
            while (j < L && b[j] == key) {
                mn = min(mn, (int)a[j]);
                mx = max(mx, (int)a[j]);
                j++;
            }
            int cnt = j - i;
            if (cnt >= N) {
                int width = mx - mn;
                int swaps = width - (N - 1);
                if (swaps < ans) ans = swaps;
            }
            i = j;
        }

        cout << ans << "\n";
    }
    return 0;
}