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
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<pair<int,long long>> ops;
        ops.reserve(N);
        for (int i = 0; i < N; i++) {
            int o;
            long long x;
            cin >> o >> x;
            ops.push_back({o, x});
        }

        bool okStack = true, okQueue = true;
        vector<long long> st;
        deque<long long> q;

        unordered_map<long long, long long> cnt;
        cnt.reserve((size_t)N * 2 + 1);

        for (auto [o, x] : ops) {
            if (o == 1) {
                cnt[x]++;
                st.push_back(x);
                q.push_back(x);
            } else {
                auto it = cnt.find(x);
                if (it == cnt.end() || it->second == 0) {
                    okStack = okQueue = false;
                    break;
                }
                it->second--;
                if (it->second == 0) cnt.erase(it);

                if (okStack) {
                    if (st.empty() || st.back() != x) okStack = false;
                    else st.pop_back();
                }
                if (okQueue) {
                    if (q.empty() || q.front() != x) okQueue = false;
                    else q.pop_front();
                }
                if (!okStack && !okQueue) break;
            }
        }

        string ans;
        if (okStack && okQueue) ans = "ambas";
        else if (okStack) ans = "pilha";
        else if (okQueue) ans = "fila";
        else ans = "nenhuma";

        cout << "caso " << tc << ": " << ans << "\n";
    }
    return 0;
}