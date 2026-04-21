/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;
    vector<long long> R_tariff(M);
    for (int i = 0; i < M; ++i) {
        cin >> R_tariff[i];
    }

    int N;
    if (!(cin >> N)) return 0;
    vector<int> Q_city(N);
    for (int i = 0; i < N; ++i) {
        cin >> Q_city[i];
    }

    int W;
    if (!(cin >> W)) return 0;
    vector<vector<Edge>> adj(N);
    for (int i = 0; i < W; ++i) {
        int u, v, z;
        cin >> u >> v >> z;
        if (u >= 0 && u < N && v >= 0 && v < N) {
            adj[u].push_back({v, z});
            adj[v].push_back({u, z});
        }
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "RIDE") {
            int C, D;
            char O;
            cin >> C >> D >> O;
            
            vector<pair<long long, long long>> min_cost(N, {INF, INF});
            using State = pair<pair<long long, long long>, int>;
            priority_queue<State, vector<State>, greater<State>> pq;

            min_cost[C] = {0, 0};
            pq.push({{0, 0}, C});

            while (!pq.empty()) {
                pair<long long, long long> cur_c = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (cur_c > min_cost[u]) continue;
                if (u == D) break;

                for (auto& edge : adj[u]) {
                    int v = edge.to;
                    long long length = edge.dist;
                    long long price = R_tariff[Q_city[u]] * length;
                    
                    pair<long long, long long> next_c;
                    if (O == 'S') {
                        next_c = {cur_c.first + length, cur_c.second + price};
                    } else {
                        next_c = {cur_c.first + price, cur_c.second + length};
                    }

                    if (next_c < min_cost[v]) {
                        min_cost[v] = next_c;
                        pq.push({min_cost[v], v});
                    }
                }
            }

            if (O == 'S') {
                cout << min_cost[D].first << " " << min_cost[D].second << "\n";
            } else {
                cout << min_cost[D].second << " " << min_cost[D].first << "\n";
            }
        } else if (cmd == "UPDA") {
            int J;
            long long newTariff;
            cin >> J >> newTariff;
            if (J >= 0 && J < M) {
                R_tariff[J] = newTariff;
            }
        }
    }

    return 0;
}