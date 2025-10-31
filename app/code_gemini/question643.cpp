/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

struct Point {
    long long x, y;
};

std::vector<std::vector<int>> adj;
std::vector<int> match;
std::vector<bool> visited;

bool dfs_match(int u) {
    if (visited[u]) {
        return false;
    }
    visited[u] = true;
    for (int v : adj[u]) {
        int w = match[v];
        if (w == -1 || dfs_match(w)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool is_outside(long long px, long long py, int N, const std::vector<Point>& polygon) {
    for (int i = 0; i < N; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % N];
        
        __int128 cross_product = (__int128)(p2.x - p1.x) * (py - p1.y) - (__int128)(p2.y - p1.y) * (px - p1.x);

        if (cross_product == 0) {
            if (px >= std::min(p1.x, p2.x) && px <= std::max(p1.x, p2.x) &&
                py >= std::min(p1.y, p2.y) && py <= std::max(p1.y, p2.y)) {
                return false;
            }
        }
    }

    int intersections = 0;
    for (int i = 0; i < N; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % N];

        if (p1.x == p2.x) { // Vertical segment
            if (px < p1.x) {
                if ((p1.y <= py && p2.y > py) || (p2.y <= py && p1.y > py)) {
                    intersections++;
                }
            }
        }
    }
    return (intersections % 2 == 0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != 0) {
        std::vector<Point> polygon(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> polygon[i].x >> polygon[i].y;
        }

        std::set<long long> x_set, y_set;
        for (int i = 0; i < N; ++i) {
            Point p1 = polygon[i];
            Point p2 = polygon[(i + 1) % N];
            if (p1.x == p2.x) {
                x_set.insert(p1.x);
            } else {
                y_set.insert(p1.y);
            }
        }

        std::vector<long long> x_coords(x_set.begin(), x_set.end());
        std::vector<long long> y_coords(y_set.begin(), y_set.end());
        std::map<long long, int> x_map, y_map;
        for (size_t i = 0; i < x_coords.size(); ++i) x_map[x_coords[i]] = i;
        for (size_t i = 0; i < y_coords.size(); ++i) y_map[y_coords[i]] = i;

        int U_size = x_coords.size();
        int V_size = y_coords.size();
        
        adj.assign(U_size, std::vector<int>());

        for (long long x : x_coords) {
            for (long long y : y_coords) {
                if (is_outside(x, y, N, polygon)) {
                    adj[x_map[x]].push_back(y_map[y]);
                }
            }
        }

        int matching_size = 0;
        match.assign(V_size, -1);
        for (int u = 0; u < U_size; ++u) {
            visited.assign(U_size, false);
            if (dfs_match(u)) {
                matching_size++;
            }
        }

        std::cout << U_size + V_size - matching_size << std::endl;
    }

    return 0;
}
