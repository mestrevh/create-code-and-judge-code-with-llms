/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
vector<int> original_adj[MAXN];
vector<int> members[MAXN];
int root[MAXN];
int dists[MAXN];
int vis[MAXN];
int q[MAXN];
int timer = 0;
int version = 0;
int N_curr;

void run_bfs(int start_root) {
    timer++;
    int head = 0, tail = 0;
    q[tail++] = start_root;
    vis[start_root] = timer;
    dists[start_root] = 0;
    while (head < tail) {
        int U = q[head++];
        int d = dists[U] + 1;
        for (int u : members[U]) {
            for (int v : original_adj[u]) {
                int RV = root[v];
                if (vis[RV] < timer) {
                    vis[RV] = timer;
                    dists[RV] = d;
                    q[tail++] = RV;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    N_curr = N;
    for (int i = 0; i < N; i++) {
        root[i] = i;
        members[i].push_back(i);
        vis[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u < N && v < N && u != v) {
            original_adj[u].push_back(v);
            original_adj[v].push_back(u);
        }
    }

    int O;
    if (!(cin >> O)) return 0;

    int last_root = -1;
    int last_version = -1;

    for (int i = 0; i < O; i++) {
        char type;
        int u, v;
        cin >> type >> u >> v;
        if (type == 'c') {
            if (u < N && v < N) {
                int ru = root[u];
                int rv = root[v];
                if (ru != rv) {
                    N_curr--;
                    version++;
                    if (members[ru].size() < members[rv].size()) swap(ru, rv);
                    for (int x : members[rv]) {
                        root[x] = ru;
                        members[ru].push_back(x);
                    }
                    members[rv].clear();
                }
            }
            cout << N_curr << "\n";
        } else if (type == 'd') {
            if (u >= N || v >= N) {
                cout << "-1\n";
                continue;
            }
            int ru = root[u];
            int rv = root[v];
            if (ru == rv) {
                cout << "0\n";
            } else {
                if (version == last_version && ru == last_root) {
                    if (vis[rv] == timer) cout << dists[rv] << "\n";
                    else cout << "-1\n";
                } else if (version == last_version && rv == last_root) {
                    if (vis[ru] == timer) cout << dists[ru] << "\n";
                    else cout << "-1\n";
                } else {
                    run_bfs(ru);
                    last_root = ru;
                    last_version = version;
                    if (vis[rv] == timer) cout << dists[rv] << "\n";
                    else cout << "-1\n";
                }
            }
        }
    }

    return 0;
}