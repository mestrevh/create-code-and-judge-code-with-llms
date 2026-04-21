/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool ok = true;
        for (int x : a) if (x > d) ok = false;
        if (ok) {
            cout << "SIM\n";
            continue;
        }

        vector<int> big;
        for (int i = 0; i < n; i++) if (a[i] > d) big.push_back(i);
        if ((int)big.size() == 0) {
            cout << "SIM\n";
            continue;
        }

        vector<int> small;
        for (int i = 0; i < n; i++) if (a[i] <= d) small.push_back(i);

        bool hasTripleSmall = ((int)small.size() >= 2);

        if (!hasTripleSmall) {
            cout << "NAO\n";
            continue;
        }

        int bestSmall = INT_MAX;
        for (int idx : small) bestSmall = min(bestSmall, a[idx]);

        bool possible = true;
        for (int idx : big) {
            int x = a[idx];
            if (x <= d) continue;
            int need = x - d;
            int minSum = INT_MAX;
            for (int j = 0; j < n; j++) if (j != idx && a[j] <= d) {
                for (int k = j + 1; k < n; k++) {
                    if (k == idx) continue;
                    if (k == j) continue;
                }
            }
            minSum = INT_MAX;
            vector<int> candidates;
            for (int j : small) if (j != idx) candidates.push_back(j);

            if (candidates.size() < 2) {
                possible = false;
                break;
            }

            int first = INT_MAX, second = INT_MAX;
            for (int j : candidates) {
                int val = a[j];
                if (val < first) {
                    second = first;
                    first = val;
                } else if (val < second) {
                    second = val;
                }
            }
            if (first == INT_MAX || second == INT_MAX) {
                possible = false;
                break;
            }
            long long sumMin = (long long)first + second;
            if (sumMin > d) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "SIM\n" : "NAO\n");
    }
    return 0;
}