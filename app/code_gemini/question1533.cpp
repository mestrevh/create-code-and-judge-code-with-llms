/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct State {
    long long primary_cost;
    long long secondary_cost;
    int u;

    bool operator>(const State& other) const {
        if (primary_cost != other.primary_cost) {
            return primary_cost > other.primary_cost;
        }
        return secondary_cost > other.secondary_cost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;
    vector<long long> R(M);
    for (int i = 0; i < M; ++i) {
        cin >> R[i];
    }

    int N;
    cin >> N;
    vector<int> Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> Q[i];
    }

    int W;
    cin >> W;
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < W; ++i) {
        int u, v, z;
        cin >> u >> v >> z;
        adj[u].push_back({v, z});
        adj[v].push_back({u, z});
    }

    string command;
    while (cin >> command) {
        if (command == "RIDE") {
            int C, D;
            char O;
            cin >> C >> D >> O;

            vector<pair<long long, long long>> dist(N, {INF, INF});
            priority_queue<State, vector<State>, greater<State>> pq;

            dist[C] = {0, 0};
            pq.push({0, 0, C});

            while (!pq.empty()) {
                State current = pq.top();
                pq.pop();

                long long p_cost = current.primary_cost;
                long long s_cost = current.secondary_cost;
                int u = current.u;

                if (p_cost > dist[u].first || (p_cost == dist[u].first && s_cost > dist[u].second)) {
                    continue;
                }

                if (u == D) {
                    break;
                }

                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int length = edge.second;
                    long long price = (long long)length * R[Q[u]];

                    long long new_p_cost, new_s_cost;
                    if (O == 'S') {
                        new_p_cost = p_cost + length;
                        new_s_cost = s_cost + price;
                    } else { // O == 'E'
                        new_p_cost = p_cost + price;
                        new_s_cost = s_cost + length;
                    }

                    if (new_p_cost < dist[v].first || (new_p_cost == dist[v].first && new_s_cost < dist[v].second)) {
                        dist[v] = {new_p_cost, new_s_cost};
                        pq.push({new_p_cost, new_s_cost, v});
                    }
                }
            }

            if (O == 'S') {
                cout << dist[D].first << " " << dist[D].second << "\n";
            } else { // O == 'E'
                cout << dist[D].second << " " << dist[D].first << "\n";
            }

        } else if (command == "UPDA") {
            int J;
            long long new_R;
            cin >> J >> new_R;
            R[J] = new_R;
        }
    }

    return 0;
}
