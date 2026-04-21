/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    while (cin >> N >> X) {
        if (N == -1 && X == -1) break;

        vector<long long> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        vector<long long> sorted = a;
        sort(sorted.begin(), sorted.end());

        long long cnt = 0;
        vector<int> pos;
        vector<long long> vals;

        for (int i = 0; i < N; i++) {
            long long diff = llabs(sorted[i] - a[i]);
            if (diff == X) {
                cnt++;
                vals.push_back(sorted[i]);
                pos.push_back(i);
            }
        }

        cout << cnt << "\n";
        for (size_t k = 0; k < vals.size(); k++) {
            if (k) cout << "\n";
            cout << vals[k] << " " << X << " " << pos[k] + 1;
        }
        if (!vals.empty()) cout << "\n";
        if (vals.empty()) cout << "\n";
    }
    return 0;
}