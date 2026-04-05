/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    if (!(cin >> Q)) return 0;
    while (Q--) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int bestCount = -1;
        int bestX = a.front();

        int l = 0;
        for (int r = 0; r < N; r++) {
            while (a[r] - a[l] > 2 * K) l++;
            int cnt = r - l + 1;
            if (cnt > bestCount) {
                bestCount = cnt;
                bestX = a[r];
            } else if (cnt == bestCount && a[r] < bestX) {
                bestX = a[r];
            }
        }

        cout << bestX << "\n";
    }
    return 0;
}