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
        cin >> N;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        int bestLen = 0;
        int bestStart = 0;

        int i = 0;
        while (i < N) {
            int j = i;
            while (j + 1 < N && a[j] > a[j + 1]) j++;
            int len = j - i + 1;
            if (len > bestLen) {
                bestLen = len;
                bestStart = i;
            }
            i = j + 1;
        }

        cout << bestLen << "\n";
        if (bestLen > 0) {
            for (int k = 0; k < bestLen; k++) {
                if (k) cout << ' ';
                cout << a[bestStart + k];
            }
            cout << "\n";
        }
        if (T) {
            ;
        }
    }
    return 0;
}