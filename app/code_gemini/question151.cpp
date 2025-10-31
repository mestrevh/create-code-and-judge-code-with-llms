/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

struct Point {
    double x, y;
};

double dist(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        if (n <= 1) {
            std::cout << std::fixed << std::setprecision(2) << 0.00 << std::endl;
            continue;
        }

        std::vector<double> min_cost(n, std::numeric_limits<double>::max());
        std::vector<bool> visited(n, false);
        double total_cost = 0.0;

        min_cost[0] = 0.0;

        for (int i = 0; i < n; ++i) {
            int u = -1;

            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || min_cost[j] < min_cost[u])) {
                    u = j;
                }
            }

            if (min_cost[u] == std::numeric_limits<double>::max()) {
                break;
            }

            visited[u] = true;
            total_cost += min_cost[u];

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    double weight = dist(points[u], points[v]);
                    if (weight < min_cost[v]) {
                        min_cost[v] = weight;
                    }
                }
            }
        }

        std::cout << std::fixed << std::setprecision(2) << total_cost << std::endl;
    }

    return 0;
}
