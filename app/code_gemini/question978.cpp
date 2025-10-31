/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <numeric>
#include <functional>

struct Point {
    int x, y;
};

int N;
std::vector<Point> warehouses;
std::vector<std::vector<int>> dist_matrix;

int manhattan_dist(const Point& p1, const Point& p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

void precompute_distances() {
    dist_matrix.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist_matrix[i][j] = manhattan_dist(warehouses[i], warehouses[j]);
        }
    }
}

int solveA() {
    std::vector<bool> visited(N, false);
    int current_cost = 0;
    
    int current_node = 0;
    visited[current_node] = true;

    for (int i = 0; i < N - 1; ++i) {
        int next_node = -1;
        int min_dist = std::numeric_limits<int>::max();
        
        for (int j = 0; j < N; ++j) {
            if (!visited[j]) {
                int d = dist_matrix[current_node][j];
                if (d < min_dist) {
                    min_dist = d;
                    next_node = j;
                } else if (d == min_dist) {
                    if (next_node == -1 || j < next_node) {
                        next_node = j;
                    }
                }
            }
        }
        
        current_cost += min_dist;
        current_node = next_node;
        visited[current_node] = true;
    }
    
    current_cost += dist_matrix[current_node][0];
    return current_cost;
}

int best_cost_B;
std::vector<int> min1_dist_B, min2_dist_B;
std::vector<int> path_B;
std::vector<bool> visited_B;

void backtrack_B(int k, int current_cost) {
    if (k == N) {
        best_cost_B = std::min(best_cost_B, current_cost + dist_matrix[path_B.back()][0]);
        return;
    }
    
    long long remaining_bound_sum = 0;
    for(int i = 0; i < N; ++i) {
        if (!visited_B[i]) {
            remaining_bound_sum += (min1_dist_B[i] + min2_dist_B[i]);
        }
    }
    
    if (static_cast<long long>(current_cost) + (remaining_bound_sum + 1) / 2 >= best_cost_B) {
        return;
    }

    int prev_node = path_B.back();
    for (int i = 1; i < N; ++i) {
        if (!visited_B[i]) {
            path_B.push_back(i);
            visited_B[i] = true;
            
            backtrack_B(k + 1, current_cost + dist_matrix[prev_node][i]);
            
            visited_B[i] = false;
            path_B.pop_back();
        }
    }
}

int solveB() {
    min1_dist_B.assign(N, std::numeric_limits<int>::max());
    min2_dist_B.assign(N, std::numeric_limits<int>::max());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int d = dist_matrix[i][j];
            if (d < min1_dist_B[i]) {
                min2_dist_B[i] = min1_dist_B[i];
                min1_dist_B[i] = d;
            } else if (d < min2_dist_B[i]) {
                min2_dist_B[i] = d;
            }
        }
    }

    best_cost_B = solveA(); 
    
    path_B.clear();
    path_B.push_back(0);
    visited_B.assign(N, false);
    visited_B[0] = true;
    
    backtrack_B(1, 0);
    
    return best_cost_B;
}

void dfs_C(int u, std::vector<std::vector<int>>& mst_adj, std::vector<bool>& visited, std::vector<int>& tour) {
    visited[u] = true;
    tour.push_back(u);
    for (int v : mst_adj[u]) {
        if (!visited[v]) {
            dfs_C(v, mst_adj, visited, tour);
        }
    }
}

int solveC() {
    std::vector<std::vector<int>> mst_adj(N);
    std::vector<bool> in_mst(N, false);
    
    in_mst[0] = true;
    for (int edges_added = 0; edges_added < N - 1; ++edges_added) {
        int best_dist = std::numeric_limits<int>::max();
        int best_u = -1, best_v = -1;
        
        for (int u = 0; u < N; ++u) {
            if (in_mst[u]) {
                for (int v = 0; v < N; ++v) {
                    if (!in_mst[v]) {
                        int d = dist_matrix[u][v];
                        if (d < best_dist) {
                            best_dist = d;
                            best_u = u;
                            best_v = v;
                        } else if (d == best_dist) {
                            if (u < best_u) {
                                best_u = u;
                                best_v = v;
                            } else if (u == best_u && v < best_v) {
                                best_v = v;
                            }
                        }
                    }
                }
            }
        }
        
        in_mst[best_v] = true;
        mst_adj[best_u].push_back(best_v);
        mst_adj[best_v].push_back(best_u);
    }
    
    for (int i = 0; i < N; ++i) {
        std::sort(mst_adj[i].begin(), mst_adj[i].end());
    }
    
    std::vector<int> tour;
    std::vector<bool> visited(N, false);
    dfs_C(0, mst_adj, visited, tour);
    
    int cost = 0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        cost += dist_matrix[tour[i]][tour[i+1]];
    }
    cost += dist_matrix[tour.back()][tour.front()];
    
    return cost;
}

void solve_case() {
    std::cin >> N;
    warehouses.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> warehouses[i].x >> warehouses[i].y;
    }

    precompute_distances();
    
    int costA = solveA();
    int costB = solveB();
    int costC = solveC();
    
    std::cout << costA << " " << costB << " " << costC << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int L;
    std::cin >> L;
    for (int i = 0; i < L; ++i) {
        std::cout << i << ": ";
        solve_case();
    }
    
    return 0;
}
