/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    int r;
    if (!(cin >> n >> k >> r)) return 0;

    vector<int> leftChild(n, -1), rightChild(n, -1);
    for (int i = 0; i < k; i++) {
        int S, L, R;
        cin >> S >> L >> R;
        leftChild[S] = L;
        rightChild[S] = R;
    }

    const int NEG = -1e9;
    vector<int> height(n, 0);
    vector<char> vis(n, 0);

    vector<pair<int,int>> st;
    st.reserve(n);
    st.push_back({r, 0});
    vis[r] = 1;

    while (!st.empty()) {
        int u = st.back().first;
        int phase = st.back().second;

        int lc = leftChild[u];
        int rc = rightChild[u];

        if (phase == 0) {
            st.back().second = 1;
            if (lc != -1 && !vis[lc]) {
                vis[lc] = 1;
                st.push_back({lc, 0});
                continue;
            }
        }
        if (phase == 1) {
            st.back().second = 2;
            if (rc != -1 && !vis[rc]) {
                vis[rc] = 1;
                st.push_back({rc, 0});
                continue;
            }
        }

        int best = 1;
        if (lc != -1) best = max(best, height[lc] + 1);
        if (rc != -1) best = max(best, height[rc] + 1);
        height[u] = best;

        st.pop_back();
    }

    cout << height[r] << "\n";
    return 0;
}