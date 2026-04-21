/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        if (N <= 1) {
            cout << fixed << setprecision(2) << 0.00 << "\n";
            continue;
        }

        vector<Edge> edges;
        edges.reserve((N * (N - 1)) / 2);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double dx = points[i].x - points[j].x;
                double dy = points[i].y - points[j].y;
                double dist = sqrt(dx * dx + dy * dy);
                edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(N);
        double total_length = 0;
        int edges_count = 0;

        for (const auto& edge : edges) {
            if (dsu.unite(edge.u, edge.v)) {
                total_length += edge.w;
                edges_count++;
                if (edges_count == N - 1) break;
            }
        }

        cout << fixed << setprecision(2) << total_length << "\n";
    }

    return 0;
}