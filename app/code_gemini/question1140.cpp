/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> c_center;
std::vector<int> d_center;
std::vector<int> memo_c;
std::vector<int> memo_d;

int get_depth_c(int u) {
    if (u == 0) {
        return 0;
    }
    if (memo_c[u] != -1) {
        return memo_c[u];
    }
    return memo_c[u] = 1 + get_depth_c(c_center[u]);
}

int get_depth_d(int v) {
    if (v == 0) {
        return 0;
    }
    if (memo_d[v] != -1) {
        return memo_d[v];
    }
    return memo_d[v] = 1 + get_depth_d(d_center[v]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    
    c_center.assign(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int id, l, k;
        std::cin >> id >> l >> k;
        if (id > 0 && id <= N) {
            c_center[id] = k;
        }
    }

    int M;
    std::cin >> M;
    d_center.assign(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        int p, q, r;
        std::cin >> p >> q >> r;
        if (p > 0 && p <= M) {
            d_center[p] = q;
        }
    }

    memo_c.assign(N + 1, -1);
    for (int i = 1; i <= N; ++i) {
        if (memo_c[i] == -1) {
            get_depth_c(i);
        }
    }

    memo_d.assign(M + 1, -1);
    for (int i = 1; i <= M; ++i) {
        if (memo_d[i] == -1) {
            get_depth_d(i);
        }
    }

    int max_depth_c = 0;
    if (N > 0) {
        for (int i = 1; i <= N; ++i) {
            if (memo_c[i] > max_depth_c) {
                max_depth_c = memo_c[i];
            }
        }
    }
    
    int max_depth_d = 0;
    if (M > 0) {
        for (int i = 1; i <= M; ++i) {
            if (memo_d[i] > max_depth_d) {
                max_depth_d = memo_d[i];
            }
        }
    }
    
    int depth_c_root = (N > 0) ? memo_c[1] : 0;
    int depth_d_root = (M > 0) ? memo_d[1] : 0;

    int saving1 = std::min(max_depth_c, depth_d_root);
    int saving2 = std::min(depth_c_root, max_depth_d);

    int max_merged = std::max(saving1, saving2);

    std::cout << N + M - max_merged << "\n";

    return 0;
}
