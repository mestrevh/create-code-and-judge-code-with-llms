/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

inline int my_abs(int v) {
    return v < 0 ? -v : v;
}

inline int get_manhattan_dist(const Point& a, const Point& b) {
    return my_abs(a.x - b.x) + my_abs(a.y - b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    if (!(cin >> L)) return 0;

    for (int k = 0; k < L; ++k) {
        int N;
        if (!(cin >> N)) break;

        vector<Point> pts(N);
        for (int i = 0; i < N; ++i) {
            cin >> pts[i].x >> pts[i].y;
        }

        if (N <= 0) {
            cout << k << ": 0\n";
            continue;
        }

        // Standard Prim's Algorithm for dense MST: O(N^2)
        // Suitable for N up to 1500 as the graph is complete.
        vector<int> min_dist(N, 2000000000);
        vector<bool> visited(N, false);
        min_dist[0] = 0;
        long long total_cost = 0;

        for (int i = 0; i < N; ++i) {
            int u = -1;
            int d_u = 2000000001;

            // Find unvisited vertex with the minimum distance to the current MST
            for (int j = 0; j < N; ++j) {
                if (!visited[j] && min_dist[j] < d_u) {
                    d_u = min_dist[j];
                    u = j;
                }
            }

            if (u == -1) break;

            visited[u] = true;
            total_cost += d_u;

            // Update distances of all unvisited neighbors
            for (int v = 0; v < N; ++v) {
                if (!visited[v]) {
                    int d_uv = get_manhattan_dist(pts[u], pts[v]);
                    if (d_uv < min_dist[v]) {
                        min_dist[v] = d_uv;
                    }
                }
            }
        }

        cout << k << ": " << total_cost << "\n";
    }

    return 0;
}