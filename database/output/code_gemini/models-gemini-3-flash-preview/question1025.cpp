/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int cap;
    int flow;
    int rev;
};

vector<Edge> flow_adj[5005];
int level[5005];
int ptr[5005];

void add_flow_edge(int from, int to, int cap) {
    flow_adj[from].push_back({to, cap, 0, (int)flow_adj[to].size()});
    flow_adj[to].push_back({from, 0, 0, (int)flow_adj[from].size() - 1});
}

bool bfs(int s, int t, int n) {
    for (int i = 0; i <= n; ++i) level[i] = -1;
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : flow_adj[v]) {
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
    for (int& cid = ptr[v]; cid < flow_adj[v].size(); ++cid) {
        auto& edge = flow_adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        int push = dfs(tr, t, min(pushed, edge.cap - edge.flow));
        if (push == 0) continue;
        edge.flow += push;
        flow_adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

int dinic(int s, int t, int n) {
    int flow = 0;
    while (bfs(s, t, n)) {
        for (int i = 0; i <= n; ++i) ptr[i] = 0;
        while (int pushed = dfs(s, t, 1e9)) {
            flow += pushed;
        }
    }
    return flow;
}

struct Road {
    int u, v, c, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    string line;
    getline(cin, line);
    for (int i = 0; i < k; ++i) {
        getline(cin, line);
    }

    int m;
    if (!(cin >> m)) return 0;
    vector<Road> roads;
    vector<pair<int, int>> adj[5005];
    for (int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        roads.push_back({u, v, c, d});
        adj[u].push_back({v, d});
    }

    int s, t;
    cin >> s >> t;

    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (auto& edge : adj[v]) {
            if (dist[v] + edge.second < dist[edge.to]) {
                dist[edge.to] = dist[v] + edge.second;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    if (dist[t] == INF) {
        return 0;
    }

    for (auto& road : roads) {
        if (dist[road.u] != INF && dist[road.v] != INF && dist[road.u] + road.d == dist[road.v]) {
            add_flow_edge(road.u, road.v, road.c);
        }
    }

    cout << dist[t] << "\n";
    cout << dinic(s, t, n) << endl;

    return 0;
}