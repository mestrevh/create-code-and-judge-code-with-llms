/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> depth, parent, points;
unordered_map<int, vector<int>> card_positions;

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node] = par;
    for (int neighbor : graph[node]) {
        if (neighbor != par) {
            dfs(neighbor, node, d + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    while (depth[a] > depth[b]) a = parent[a];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    int N;
    cin >> N;
    graph.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    points.resize(N + 1);
    vector<int> cards(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> cards[i];
        card_positions[cards[i]].push_back(i);
    }

    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1, 0);
    
    int max_points = 0;
    for (const auto& [num, positions] : card_positions) {
        if (positions.size() == 2) {
            int a = positions[0], b = positions[1];
            int ancestor = lca(a, b);
            int distance = depth[a] + depth[b] - 2 * depth[ancestor];
            max_points += distance;
        }
    }

    cout << max_points << endl;
    return 0;
}
