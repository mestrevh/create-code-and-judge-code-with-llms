/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long w;
};

static const long long INF = (1LL<<60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    if (!(cin >> L)) return 0;

    for (int tc = 0; tc < L; tc++) {
        int M, N;
        cin >> M >> N;
        int V = M * N;

        vector<string> grid(M * N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                string s;
                cin >> s;
                grid[i * N + j] = s;
            }
        }

        int Q, P;
        cin >> Q >> P;

        vector<vector<int>> portalTo(V);
        vector<vector<int>> portalFrom(V); // not used

        portalTo.assign(V, {});
        for (int q = 0; q < Q; q++) {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            int a = i1 * N + j1;
            int b = i2 * N + j2;
            portalTo[a].push_back(b);
        }

        int S = 0;
        int T = V - 1;

        int timeStates = P;
        int totalStates = V * timeStates;

        vector<long long> dist(totalStates, INF);
        auto id = [&](int v, int t){ return v * timeStates + t; };

        using PDI = pair<long long,int>;
        priority_queue<PDI, vector<PDI>, greater<PDI>> pq;

        dist[id(S, 0)] = 0;
        pq.push({0, id(S, 0)});

        while (!pq.empty()) {
            auto [d, st] = pq.top();
            pq.pop();
            if (d != dist[st]) continue;

            int v = st / timeStates;
            int tmod = st % timeStates;

            if (v == T) {
                // do not break: there could be smaller with other tmod already processed? but Dijkstra ensures first time reaching v at minimal distance among all states not necessarily overall.
            }

            if (d % P == 0) {
                int nt = tmod;
                for (int to : portalTo[v]) {
                    long long nd = d + 1;
                    int ntime = (int)(nd % P);
                    int nid = id(to, ntime);
                    if (nd < dist[nid]) {
                        dist[nid] = nd;
                        pq.push({nd, nid});
                    }
                }
            }

            auto considerMove = [&](int ni, int nj){
                if (ni < 0 || ni >= M || nj < 0 || nj >= N) return;
                int to = ni * N + nj;
                long long nd = d + 1;
                int ntime = (int)(nd % P);
                int nid = id(to, ntime);
                if (nd < dist[nid]) {
                    dist[nid] = nd;
                    pq.push({nd, nid});
                }
            };

            int i = v / N;
            int j = v % N;
            const string &s = grid[v];
            for (char c : s) {
                if (c == 'N') considerMove(i-1, j);
                else if (c == 'S') considerMove(i+1, j);
                else if (c == 'E') considerMove(i, j+1);
                else if (c == 'W') considerMove(i, j-1);
            }

            // wait
            long long nd = d + 1;
            int ntime = (int)(nd % P);
            int nid = id(v, ntime);
            if (nd < dist[nid]) {
                dist[nid] = nd;
                pq.push({nd, nid});
            }
        }

        long long ans = INF;
        for (int t = 0; t < P; t++) {
            ans = min(ans, dist[id(T, t)]);
        }

        cout << tc << ": " << ans << "\n";
        if (tc != L - 1) {
            // There is a blank line after each case in input, but using >> parsing already skips whitespace.
        }
    }

    return 0;
}