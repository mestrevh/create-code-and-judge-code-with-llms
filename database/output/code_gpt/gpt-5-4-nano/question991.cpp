/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int start = int(min_element(a.begin(), a.end()) - a.begin());

    vector<long long> vals;
    vals.reserve(N);
    for (int k = 0; k < N; k++) vals.push_back(a[(start + k) % N]);

    int m = N;
    vector<int> nxt(m), prv(m);
    for (int i = 0; i < m; i++) {
        nxt[i] = (i + 1) % m;
        prv[i] = (i - 1 + m) % m;
    }

    auto printState = [&]() {
        int cur = 0;
        while (true) {
            cout << vals[cur];
            cur = nxt[cur];
            if (cur == 0) break;
            cout << ' ' << vals[cur];
        }
        cout << '\n';
    };

    for (int i = 0; i < Q; i++) {
        int pos;
        cin >> pos;

        int idx = (pos - start + N) % N;
        int right = nxt[idx];

        vals[idx] += vals[right];

        prv[next] = prv?; 
    }

    return 0;
}
