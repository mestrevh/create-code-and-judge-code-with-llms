/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <queue>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& e) const { return weight > e.weight; }
};

int find_parent(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = find_parent(parent[v], parent);
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& size) {
    a = find_parent(a, parent);
    b = find_parent(b, parent);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

pair<int, int> min_cost(int n, vector<Edge>& edges, int C, int R) {
    int T1 = 0, T2 = 0;

    // Proposta 1 - Kruskal para MST
    vector<int> parent1(n), size1(n, 1);
    iota(parent1.begin(), parent1.end(), 0);
    sort(edges.begin(), edges.end());

    for (Edge& e : edges) {
        if (find_parent(e.u, parent1) != find_parent(e.v, parent1)) {
            union_sets(e.u, e.v, parent1, size1);
            T1 += e.weight;
        }
    }
    T1 *= C;

    // Proposta 2 - Prim para caminho mínimo
    T2 = 0;
    vector<bool> in_mst(n, false);
    priority_queue<Edge> pq;
    in_mst[0] = true;

    for (Edge& e : edges) {
        if (e.u == 0 || in_mst[e.u]) pq.push(e);
    }

    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (in_mst[e.v]) continue;

        in_mst[e.v] = true;
        T2 += R;

        for (Edge& f : edges) {
            if (f.u == e.v && !in_mst[f.v]) pq.push(f);
            if (f.v == e.v && !in_mst[f.u]) pq.push(f);
        }
    }

    return {T1, T2};
}

int main() {
    int N, M, C, R;
    cin >> N >> M >> C >> R;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    auto result = min_cost(N, edges, C, R);
    cout << result.first << " " << result.second << endl;

    return 0;
}
