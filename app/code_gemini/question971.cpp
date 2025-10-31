/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {
    int x, y;
};

int manhattan_distance(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L;
    std::cin >> L;
    for (int k = 0; k < L; ++k) {
        int N;
        std::cin >> N;
        std::vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        if (N <= 1) {
            std::cout << k << ": 0\n";
            continue;
        }

        std::vector<long long> min_cost(N, std::numeric_limits<long long>::max());
        std::vector<bool> in_mst(N, false);
        long long total_mst_cost = 0;

        min_cost[0] = 0;

        for (int count = 0; count < N; ++count) {
            int u = -1;
            long long current_min = std::numeric_limits<long long>::max();

            for (int i = 0; i < N; ++i) {
                if (!in_mst[i] && min_cost[i] < current_min) {
                    current_min = min_cost[i];
                    u = i;
                }
            }
            
            if (u == -1) break;

            in_mst[u] = true;
            total_mst_cost += min_cost[u];

            for (int v = 0; v < N; ++v) {
                if (!in_mst[v]) {
                    int cost_uv = manhattan_distance(points[u], points[v]);
                    if (cost_uv < min_cost[v]) {
                        min_cost[v] = cost_uv;
                    }
                }
            }
        }
        std::cout << k << ": " << total_mst_cost << "\n";
    }

    return 0;
}
