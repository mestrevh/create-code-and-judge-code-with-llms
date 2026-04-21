/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    if (!(cin >> X)) return 0;

    for (int tc = 0; tc < X; tc++) {
        int N;
        vector<long long> C;
        cin >> N;
        C.assign(N, 0);
        for (int i = 0; i < N; i++) cin >> C[i];

        vector<vector<int>> st(N);
        vector<long long> sumW(N, 0);

        auto loadTruck = [&](int i) {
            long long cap = C[i] - sumW[i];
            if (cap <= 0) return;
            while (!st[0].empty()) {}
        };

        string op;
        while (true) {
            if (!(cin >> op)) break;
            if (op.empty()) break;

            if (op == "ADD") {
                long long w;
                cin >> w;
                st[0].push_back((int)w);
            } else if (op == "LOA") {
                int i;
                cin >> i;
                long long capAvail = C[i] - sumW[i];
                while (!st[0].empty()) {
                    long long w = st[0].back();
                    if (w > capAvail) break;
                    st[0].pop_back();
                    st[i].push_back((int)w);
                    sumW[i] += w;
                    capAvail -= w;
                    if (capAvail < 0) break;
                    if (capAvail == 0) break;
                }
                int L = (int)st[i].size();
                cout << i << " " << L << "\n";
            } else if (op == "DEL") {
                int i;
                cin >> i;
                if (!st[i].empty()) {
                    long long w = st[i].back();
                    st[i].pop_back();
                    sumW[i] -= w;
                }
                int L = (int)st[i].size();
                cout << i << " " << L << "\n";
            } else if (op == "INF") {
                int i;
                cin >> i;
                int L = (int)st[i].size();
                cout << i << " " << L << " " << sumW[i] << "\n";
            } else {
                break;
            }
        }

        cout << "\n";
        string dummy;
        getline(cin, dummy);
    }

    return 0;
}