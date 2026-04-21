/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FastInput {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];
    FastInput() : idx(0), size(0) {}
    inline char read() {
        if (size == idx) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }
    bool skipBlanks() {
        char c;
        do {
            c = read();
            if (!c) return false;
        } while (c <= ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f' || c == '\v');
        idx--;
        return true;
    }
    bool readInt(int &out) {
        if (!skipBlanks()) return false;
        char c = read();
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = read();
        }
        long long val = 0;
        while (c && c > ' ') {
            if (c >= '0' && c <= '9') val = val * 10 + (c - '0');
            else break;
            c = read();
        }
        out = neg ? -val : val;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    FastInput in;
    int n;
    bool firstDataset = true;
    bool ok = in.readInt(n);
    if (!ok) return 0;

    vector<int> U, V;
    while (ok) {
        int N = n;
        vector<vector<int>> g(N);
        for (int k = 0; k < N; k++) {
            int deg;
            in.readInt(deg);
            char c = 0;
            while (true) {
                c = 0;
                c = in.read();
                if (!c) break;
                if (c == ')') break;
            }
            for (int j = 0; j < deg; j++) {
                int to;
                in.readInt(to);
                if (to >= 0 && to < N) {
                    g[k].push_back(to);
                    if (k < to) {
                        U.push_back(k);
                        V.push_back(to);
                    }
                }
            }
        }

        vector<int> disc(N, -1), low(N, -1), parent(N, -1);
        vector<pair<int,int>> bridges;
        int timer = 0;

        function<void(int)> dfs = [&](int u) {
            disc[u] = low[u] = timer++;
            for (int v : g[u]) {
                if (disc[v] == -1) {
                    parent[v] = u;
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u]) {
                        int a = min(u, v), b = max(u, v);
                        bridges.push_back({a, b});
                    }
                } else if (v != parent[u]) {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };

        for (int i = 0; i < N; i++) {
            if (disc[i] == -1) dfs(i);
        }

        sort(bridges.begin(), bridges.end());
        bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());

        if (!firstDataset) cout << "\n";
        firstDataset = false;

        cout << bridges.size() << " critical links\n";
        for (auto &e : bridges) {
            cout << e.first << " - " << e.second << "\n";
        }
        ok = in.readInt(n);
    }
    return 0;
}