/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <numeric>

using LD = long double;
const LD EPS = 1e-9;

struct DSU {
    std::vector<int> parent;
    int num_components;

    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        num_components = n;
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            num_components--;
        }
    }

    int count_components() const {
        return num_components;
    }
};

struct Circle {
    LD x, y, r;
};

struct Point {
    LD x, y;
    bool operator<(const Point& other) const {
        if (std::abs(x - other.x) > EPS) {
            return x < other.x;
        }
        if (std::abs(y - other.y) > EPS) {
            return y < other.y;
        }
        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int W, H, n;
    while (std::cin >> W >> H >> n && (W || H || n)) {
        std::vector<Circle> circles(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        DSU dsu(n);
        std::set<Point> intersection_points;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                LD dx = circles[i].x - circles[j].x;
                LD dy = circles[i].y - circles[j].y;
                LD d2 = dx * dx + dy * dy;

                if (d2 < EPS) {
                    continue;
                }

                LD r1 = circles[i].r;
                LD r2 = circles[j].r;
                LD r_sum = r1 + r2;
                LD r_diff = r1 - r2;

                if (d2 > r_sum * r_sum + EPS || d2 < r_diff * r_diff - EPS) {
                    continue;
                }

                dsu.unite(i, j);

                LD d = std::sqrt(d2);
                LD a = (r1 * r1 - r2 * r2 + d2) / (2.0L * d);
                LD h2 = r1 * r1 - a * a;
                if (h2 < 0) h2 = 0;
                LD h = std::sqrt(h2);

                LD x_mid = circles[i].x + a * dx / d;
                LD y_mid = circles[i].y + a * dy / d;

                Point p1, p2;
                p1.x = x_mid + h * dy / d;
                p1.y = y_mid - h * dx / d;
                
                p2.x = x_mid - h * dy / d;
                p2.y = y_mid + h * dx / d;

                intersection_points.insert(p1);
                intersection_points.insert(p2);
            }
        }

        int V = intersection_points.size();
        int C = dsu.count_components();

        std::cout << V + C + 1 << std::endl;
    }

    return 0;
}
