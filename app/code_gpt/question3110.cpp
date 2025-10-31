/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX_V = 101;
const int INF = numeric_limits<int>::max();

int V, A;
vector<pair<int, int>> adj[MAX_V];
int dist[MAX_V][MAX_V];

void dijkstra(int start) {
    fill(dist[start], dist[start] + V + 1, INF);
    dist[start][start] = 0;
    vector<bool> visited(V + 1, false);
    
    for (int i = 1; i <= V; i++) {
        int u = -1;
        for (int j = 1; j <= V; j++) {
            if (!visited[j] && (u == -1 || dist[start][j] < dist[start][u])) {
                u = j;
            }
        }
        visited[u] = true;
        for (auto edge : adj[u]) {
            int v = edge.first, cost = edge.second;
            if (dist[start][u] + cost < dist[start][v]) {
                dist[start][v] = dist[start][u] + cost;
            }
        }
    }
}

int color(int u) {
    int sum = 0;
    for (auto v : adj[u]) {
        sum += v.first;
    }
    return sum % 2 == 0 ? 0 : 1; // 0 for red, 1 for blue
}

int main() {
    cin >> V >> A;
    
    for (int i = 0; i < A; i++) {
        int S, D, C;
        cin >> S >> D >> C;
        adj[S].emplace_back(D, C);
        adj[D].emplace_back(S, C);
    }
    
    for (int i = 1; i <= V; i++) {
        dijkstra(i);
    }

    vector<tuple<int, int, int>> red_pairs, blue_pairs;

    for (int i = 1; i <= V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (color(i) == color(j) && dist[i][j] < INF) {
                if (color(i) == 0) {
                    red_pairs.emplace_back(dist[i][j], i, j);
                } else {
                    blue_pairs.emplace_back(dist[i][j], i, j);
                }
            }
        }
    }

    sort(red_pairs.rbegin(), red_pairs.rend());
    sort(blue_pairs.rbegin(), blue_pairs.rend());

    cout << get<1>(red_pairs[0]) << " " << get<2>(red_pairs[0]) << endl;
    cout << get<1>(blue_pairs[0]) << " " << get<2>(blue_pairs[0]) << endl;

    return 0;
}
