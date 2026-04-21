/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct FastIO {
    static const int S = 1 << 20;
    int inpos = 0, inlen = 0;
    char ibuf[S];
    FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }
    inline char read() {
        if (inpos == inlen) {
            inlen = (int)fread(ibuf, 1, S, stdin);
            inpos = 0;
            if (inlen == 0) return 0;
        }
        return ibuf[inpos++];
    }
    template<class T>
    bool readInt(T &out) {
        char c;
        do {
            c = read();
            if (!c) return false;
        } while (c <= ' ');
        bool neg = false;
        if (c == '-') { neg = true; c = read(); }
        T val = 0;
        while (c > ' ') {
            val = val * 10 + (c - '0');
            c = read();
        }
        out = neg ? -val : val;
        return true;
    }
} fio;

int main() {
    int N, M;
    while (true) {
        if (!fio.readInt(N)) return 0;
        fio.readInt(M);
        if (N == 0 && M == 0) break;

        vector<vector<int>> g(N + 1), gr(N + 1);
        g.shrink_to_fit();

        for (int i = 0; i < M; i++) {
            int V, W, P;
            fio.readInt(V);
            fio.readInt(W);
            fio.readInt(P);
            g[V].push_back(W);
            gr[W].push_back(V);
            if (P == 2) {
                g[W].push_back(V);
                gr[V].push_back(W);
            }
        }

        int s = 1;
        vector<char> vis(N + 1, 0);

        auto dfs1 = [&](auto&& self, int u) -> void {
            vis[u] = 1;
            for (int v : g[u]) if (!vis[v]) self(self, v);
        };

        dfs1(dfs1, s);
        bool ok = true;
        for (int i = 1; i <= N; i++) if (!vis[i]) { ok = false; break; }

        if (ok) {
            fill(vis.begin(), vis.end(), 0);
            function<void(int)> dfs2 = [&](int u) {
                vis[u] = 1;
                for (int v : gr[u]) if (!vis[v]) dfs2(v);
            };
            dfs2(s);
            for (int i = 1; i <= N; i++) if (!vis[i]) { ok = false; break; }
        }

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}