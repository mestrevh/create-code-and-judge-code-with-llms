/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    int parent[N + 1];
    fill_n(parent, N + 1, -1);
    int mstWeight = 0;

    for (const auto& edge : edges) {
        int u = findParent(parent, edge.u);
        int v = findParent(parent, edge.v);
        if (u != v) {
            mstWeight += edge.weight;
            unionSets(parent, u, v);
        }
    }

    cout << mstWeight << endl;
    return 0;
}
