/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct Edge {
    int u, v;
    double weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu != pv) {
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
}

double kruskal(vector<Point>& points) {
    int n = points.size();
    vector<Edge> edges;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, distance(points[i], points[j])});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    
    double totalWeight = 0.0;
    for (const Edge& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unionSets(parent, rank, edge.u, edge.v);
            totalWeight += edge.weight;
        }
    }
    
    return totalWeight;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        double result = kruskal(points);
        cout << fixed << setprecision(2) << result << endl;
    }
    return 0;
}
