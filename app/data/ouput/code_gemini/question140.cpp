/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/ing with code only, as requested.

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include <queue>
#include <tuple>
#include <algorithm>

const double INF = std::numeric_limits<double>::infinity();
const double EPS = 1e-9;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

struct Segment {
    Point p1, p2;
};

bool is_visible(Point p1, Point p2, const std::vector<Segment>& murals) {
    Segment path = {p1, p2};
    for (const auto& mural : murals) {
        double x1 = path.p1.x, y1 = path.p1.y;
        double x2 = path.p2.x, y2 = path.p2.y;
        double x3 = mural.p1.x, y3 = mural.p1.y;
        double x4 = mural.p2.x, y4 = mural.p2.y;

        double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

        if (std::abs(den) < EPS) { // Parallel or collinear
            // Check for collinear overlap on the interior of the mural
            double d1 = (x3 - x1)*(y2 - y1) - (y3 - y1)*(x2-x1);
            if (std::abs(d1) < EPS) { // Collinear
                double path_min_x = std::min(x1, x2), path_max_x = std::max(x1, x2);
                double path_min_y = std::min(y1, y2), path_max_y = std::max(y1, y2);
                double mural_min_x = std::min(x3, x4), mural_max_x = std::max(x3, x4);
                double mural_min_y = std::min(y3, y4), mural_max_y = std::max(y3, y4);

                double overlap_min_x = std::max(path_min_x, mural_min_x);
                double overlap_max_x = std::min(path_max_x, mural_max_x);
                double overlap_min_y = std::max(path_min_y, mural_min_y);
                double overlap_max_y = std::min(path_max_y, mural_max_y);
                
                if (overlap_max_x - overlap_min_x > EPS || overlap_max_y - overlap_min_y > EPS) {
                    // They overlap over a segment, not just a point
                    return false;
                }
                if (overlap_max_x > overlap_min_x + EPS && overlap_max_y > overlap_min_y + EPS) {
                    return false;
                }
                // Check if an endpoint of one lies on the interior of the other
                 if (dist(p1,mural.p1) + dist(mural.p1, p2) < dist(p1,p2) + EPS && dist(mural.p1, p1) > EPS && dist(mural.p1, p2) > EPS) return false;
                 if (dist(p1,mural.p2) + dist(mural.p2, p2) < dist(p1,p2) + EPS && dist(mural.p2, p1) > EPS && dist(mural.p2, p2) > EPS) return false;
                 if (dist(mural.p1,p1) + dist(p1, mural.p2) < dist(mural.p1,mural.p2) + EPS && dist(p1,mural.p1) > EPS && dist(p1,mural.p2) > EPS) return false;
                 if (dist(mural.p1,p2) + dist(p2, mural.p2) < dist(mural.p1,mural.p2) + EPS && dist(p2,mural.p1) > EPS && dist(p2,mural.p2) > EPS) return false;
            }
        } else {
            double t_num = (x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4);
            double u_num = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3));

            double t = t_num / den;
            double u = u_num / den;
            
            if (t > EPS && t < 1.0 - EPS && u > EPS && u < 1.0 - EPS) {
                return false;
            }
        }
    }
    return true;
}

void solve(int T, int M, int C) {
    std::vector<Segment> murals(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> murals[i].p1.x >> murals[i].p1.y >> murals[i].p2.x >> murals[i].p2.y;
    }

    int N = 2 + C + 2*M;
    std::vector<Point> nodes(N);
    
    // 0: Start, 1: Portal
    // 2 to C+1: Cabins
    // C+2 to C+1+2M: Mural endpoints

    for (int i = 0; i < C; ++i) {
        std::cin >> nodes[2 + i].x >> nodes[2 + i].y;
    }
    
    std::cin >> nodes[0].x >> nodes[0].y; 
    std::cin >> nodes[1].x >> nodes[1].y; 

    for (int i = 0; i < M; ++i) {
        nodes[2 + C + 2 * i] = murals[i].p1;
        nodes[2 + C + 2 * i + 1] = murals[i].p2;
    }
    
    std::vector<std::vector<double>> walk_adj(N, std::vector<double>(N, INF));
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (is_visible(nodes[i], nodes[j], murals)) {
                walk_adj[i][j] = walk_adj[j][i] = dist(nodes[i], nodes[j]);
            }
        }
    }

    std::vector<std::vector<double>> min_dist(N, std::vector<double>(T + 1, INF));
    using State = std::tuple<double, int, int>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    int start_node = 0;
    int portal_node = 1;

    min_dist[start_node][0] = 0.0;
    pq.push({0.0, start_node, 0});

    while (!pq.empty()) {
        auto [d, u, k] = pq.top();
        pq.pop();

        if (d > min_dist[u][k] + EPS) {
            continue;
        }

        // Walk
        for (int v = 0; v < N; ++v) {
            if (walk_adj[u][v] != INF) {
                double walk_d = walk_adj[u][v];
                if (min_dist[u][k] + walk_d < min_dist[v][k] - EPS) {
                    min_dist[v][k] = min_dist[u][k] + walk_d;
                    pq.push({min_dist[v][k], v, k});
                }
            }
        }

        // Teleport
        bool u_is_cabin = (u >= 2 && u < 2 + C);
        if (u_is_cabin && k < T) {
            for (int v = 2; v < 2 + C; ++v) {
                if (u == v) continue;
                if (walk_adj[u][v] != INF) {
                    int next_k = k + 1;
                    if (min_dist[u][k] < min_dist[v][next_k] - EPS) {
                        min_dist[v][next_k] = min_dist[u][k];
                        pq.push({min_dist[v][next_k], v, next_k});
                    }
                }
            }
        }
    }

    double final_ans = INF;
    for (int k = 0; k <= T; ++k) {
        final_ans = std::min(final_ans, min_dist[portal_node][k]);
    }

    std::cout << std::fixed << std::setprecision(1) << final_ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, M, C;
    while (std::cin >> T >> M >> C && (T != -1 || M != -1 || C != -1)) {
        solve(T, M, C);
    }
    return 0;
}
