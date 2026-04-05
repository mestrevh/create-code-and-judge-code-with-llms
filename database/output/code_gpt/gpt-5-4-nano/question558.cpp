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
        string A, B;
        cin >> A >> B;

        int n = (int)A.size(), m = (int)B.size();
        if (n == 0) {
            cout << m << "\n";
            continue;
        }
        if (m == 0) {
            cout << n << "\n";
            continue;
        }

        if (m > n) {
            swap(A, B);
            swap(n, m);
        }

        vector<int> prev(m + 1), cur(m + 1);
        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            char ca = A[i - 1];
            for (int j = 1; j <= m; j++) {
                int cost = (ca == B[j - 1]) ? 0 : 1;
                int del = prev[j] + 1;
                int ins = cur[j - 1] + 1;
                int sub = prev[j - 1] + cost;
                cur[j] = min({del, ins, sub});
            }
            swap(prev, cur);
        }

        cout << prev[m] << "\n";
    }
    return 0;
}