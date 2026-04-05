/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int interval;
};

vector<Edge> adj[1005];

void solve(int t_case) {
    string origin_s, dest_s;
    int y_travel, m_lines;
    if (!(cin >> origin_s >> dest_s >> y_travel >> m_lines)) return;

    for (int i = 0; i < 1005; ++i) adj[i].clear();
    map<string, int> ids;
    auto get_id = [&](const string& s) {
        auto it = ids.find(s);
        if (it == ids.end()) {
            int new_id = ids.size();
            ids[s] = new_id;
            return new_id;
        }
        return it->second;
    };

    int start_id = get_id(origin_s);
    int end_id = get_id(dest_s);

    for (int i = 0; i < m_lines; ++i) {
        string u_s, v_s;
        int x_interval;
        cin >> u_s >> v_s >> x_interval;
        int u = get_id(u_s);
        int v = get_id(v_s);
        if (u < 1005 && v < 1005) {
            adj[u].push_back({v, x_interval});
        }
    }

    int n = ids.size();
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    if (start_id < n) {
        dist[start_id] = 0;
        pq.push({0, start_id});
    }

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == end_id) break;

        for (auto& edge : adj[u]) {
            int v = edge.to;
            int x = edge.interval;
            long long wait = (x - (d % x)) % x;
            long long next_d = d + wait + y_travel;

            if (next_d < dist[v]) {
                dist[v] = next_d;
                pq.push({next_d, v});
            }
        }
    }

    cout << "Caso #" << t_case << ": ";
    if (end_id >= n || dist[end_id] == INF) {
        cout << "Destino inalcancavel" << endl;
    } else {
        cout << dist[end_id] << " anticalmas" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}