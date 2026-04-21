/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long capacity;
    int rev;
};

struct Dinic {
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;

    Dinic(int n) : adj(n), level(n), ptr(n) {}

    void add_edge(int from, int to, long long capacity) {
        adj[from].push_back({to, capacity, (int)adj[to].size()});
        adj[to].push_back({from, 0, (int)adj[from].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& edge : adj[v]) {
                if (edge.capacity > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, int t, long long pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
            auto& edge = adj[v][cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.capacity == 0) continue;
            long long tr_pushed = dfs(tr, t, min(pushed, edge.capacity));
            if (tr_pushed == 0) continue;
            edge.capacity -= tr_pushed;
            adj[tr][edge.rev].capacity += tr_pushed;
            return tr_pushed;
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

struct Card {
    int h, p;
    vector<int> at;
};

int solve_turns(int n, const vector<Card>& attackers, const vector<Card>& defenders) {
    long long total_h = 0;
    for (int i = 0; i < n; ++i) total_h += defenders[i].h;

    int low = 1, high = 1000000, ans = 1000001;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        Dinic din(2 * n + 2);
        int S = 0, T = 2 * n + 1;
        for (int i = 0; i < n; ++i) {
            din.add_edge(S, i + 1, (long long)mid * attackers[i].p);
            for (int target : attackers[i].at) {
                if (target >= 0 && target < n) {
                    din.add_edge(i + 1, n + target + 1, INF);
                }
            }
            din.add_edge(n + i + 1, T, defenders[i].h);
        }

        if (din.max_flow(S, T) >= total_h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Card> entity(n), x(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> entity[i].h >> entity[i].p >> k;
        entity[i].at.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> entity[i].at[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> x[i].h >> x[i].p >> k;
        x[i].at.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> x[i].at[j];
        }
    }

    int t_entity = solve_turns(n, entity, x);
    int t_x = solve_turns(n, x, entity);

    if (t_entity <= t_x) {
        cout << "Entity wins in " << t_entity << " turns" << endl;
    } else {
        cout << "X wins in " << t_x << " turns" << endl;
    }

    return 0;
}