/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX_T = 1100;
const int MAX_N = 51;
const int MAXV = MAX_T * MAX_N + 500;

struct Edge {
    int to, cap, flow, rev;
};

vector<Edge> adj[MAXV];
int level[MAXV];
int ptr[MAXV];

void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

bool bfs(int s, int t, int max_node) {
    for (int i = 0; i <= max_node; ++i) level[i] = -1;
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (const auto& edge : adj[v]) {
            if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        int push = dfs(tr, t, min(pushed, edge.cap - edge.flow));
        if (push == 0) continue;
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

int dinic(int s, int t, int max_node) {
    int flow = 0;
    while (bfs(s, t, max_node)) {
        for (int i = 0; i <= max_node; ++i) ptr[i] = 0;
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

struct Flight {
    int o, d, s;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, A;
    while (cin >> N >> M >> A && (N != 0 || M != 0 || A != 0)) {
        for (int i = 0; i < MAXV; ++i) adj[i].clear();
        vector<Flight> flights(M);
        for (int i = 0; i < M; ++i) {
            cin >> flights[i].o >> flights[i].d >> flights[i].s;
        }

        int SOURCE = 1; // (airport 1, day 0)
        int SINK = 0;
        int total_flow = 0;
        
        for (int T = 1; T < MAX_T; ++T) {
            // Wait edges: airport i at T-1 to i at T
            for (int i = 1; i <= N; ++i) {
                add_edge((T - 1) * N + i, T * N + i, A);
            }
            // Flight edges: origin at T-1 to destination at T
            for (int i = 0; i < M; ++i) {
                add_edge((T - 1) * N + flights[i].o, T * N + flights[i].d, flights[i].s);
            }
            // Sink edge: Beijing (N) at time T to super-sink
            add_edge(T * N + N, SINK, A);
            
            int current_max_node = T * N + N;
            total_flow += dinic(SOURCE, SINK, current_max_node);
            
            if (total_flow >= A) {
                cout << T << "\n";
                break;
            }
        }
    }

    return 0;
}

