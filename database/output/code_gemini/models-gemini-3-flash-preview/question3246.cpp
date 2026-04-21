/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int id;
};

vector<Edge> adj[1005];
bool used_edge[1005];
vector<int> res;

void find_path(int u) {
    while (!adj[u].empty()) {
        Edge e = adj[u].back();
        adj[u].pop_back();
        if (used_edge[e.id]) continue;
        used_edge[e.id] = true;
        find_path(e.to);
    }
    res.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    if (M == 0) {
        cout << "Yes" << endl << 0 << endl;
        return 0;
    }

    vector<int> degree(1005, 0);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u > 1000 || v < 0 || v > 1000) continue;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    int odd_count = 0;
    vector<int> odds;
    int min_node_with_edge = -1;

    for (int i = 0; i <= 1000; ++i) {
        if (degree[i] > 0) {
            if (min_node_with_edge == -1) min_node_with_edge = i;
            if (degree[i] % 2 != 0) {
                odd_count++;
                odds.push_back(i);
            }
        }
    }

    if (odd_count != 0 && odd_count != 2) {
        cout << "No" << endl;
        return 0;
    }

    int start_node = -1;
    if (odd_count == 2) {
        start_node = odds[0];
    } else {
        start_node = min_node_with_edge;
    }

    if (start_node == -1) {
        cout << "No" << endl;
        return 0;
    }

    find_path(start_node);

    if ((int)res.size() != M + 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        reverse(res.begin(), res.end());
        for (int i = 0; i < (int)res.size(); ++i) {
            cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}