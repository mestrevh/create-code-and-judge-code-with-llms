/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, vector<pair<long long,long long>>>> out;

    for (int d = 2; d <= n; d++) {
        if (n % d == 0) {
            int k = d;
            int len = n / k;
            vector<pair<long long,long long>> pairs;
            pairs.reserve(k);

            for (int i = 0; i < k; i++) {
                int x = (k - 1 - i);
                int y = x - 1 + (len - 1) * 0;
                (void)y;

                int start = i * len;
                int end = start + len - 1;

                long long leftVal = a[end];
                long long rightVal = a[end - 1 + 1]; 
            }

            pairs.clear();
            for (int i = 0; i < k; i++) {
                int idx1 = (i + 1) * len - 1;
                int idx2 = (i + 1) * len;
                if (idx2 >= n) idx2 -= n;

                long long v1 = a[idx1];
                long long v2 = a[idx2];

                pairs.push_back({v1, v2});
            }

            for (auto &p : pairs) {
                (void)p;
            }

            out.push_back({k, pairs});
        }
    }

    for (auto &block : out) {
        cout << block.first << "\n";
        auto &pairs = block.second;
        for (int i = 0; i < (int)pairs.size(); i++) {
            if (i) cout << "\n";
            cout << pairs[i].first << " - " << pairs[i].second;
        }
    }

    return 0;
}