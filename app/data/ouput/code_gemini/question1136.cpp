/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

const int MAXN = 50005;
const int MAX_NODES = MAXN * 25;

struct Node {
    int count;
    int left, right;
};

Node tree[MAX_NODES];
int roots[MAXN];
int node_count = 0;

int new_node() {
    ++node_count;
    tree[node_count].count = 0;
    tree[node_count].left = 0;
    tree[node_count].right = 0;
    return node_count;
}

int update(int prev, int l, int r, int val) {
    int curr = new_node();
    tree[curr] = tree[prev];
    tree[curr].count++;

    if (l == r) return curr;

    int mid = l + (r - l) / 2;
    if (val <= mid) {
        tree[curr].left = update(tree[prev].left, l, mid, val);
    } else {
        tree[curr].right = update(tree[prev].right, mid + 1, r, val);
    }
    return curr;
}

int count_le(int root_l, int root_r, int l, int r, int val) {
    if (val < l || root_r == 0) return 0;
    if (r <= val) {
        return tree[root_r].count - tree[root_l].count;
    }
    
    int mid = l + (r - l) / 2;
    int res = count_le(tree[root_l].left, tree[root_r].left, l, mid, val);
    if (val > mid) {
       res += count_le(tree[root_l].right, tree[root_r].right, mid + 1, r, val);
    }
    return res;
}

int query_kth(int root_l, int root_r, int l, int r, int k) {
    if (l == r) return l;
    
    int mid = l + (r - l) / 2;
    int left_count = tree[tree[root_r].left].count - tree[tree[root_l].left].count;
    
    if (k <= left_count) {
        return query_kth(tree[root_l].left, tree[root_r].left, l, mid, k);
    } else {
        return query_kth(tree[root_l].right, tree[root_r].right, mid + 1, r, k - left_count);
    }
}

int main() {
    fast_io();

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> p(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> p[i];
    }

    std::vector<int> final_dest(N + 1, 0);
    std::vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;

        std::vector<int> path;
        std::vector<bool> on_path(N + 1, false);
        int curr = i;

        while (!visited[curr] && !on_path[curr]) {
            on_path[curr] = true;
            path.push_back(curr);
            curr = p[curr];
        }

        if (on_path[curr]) {
            size_t cycle_start_idx = 0;
            while(path[cycle_start_idx] != curr) {
                cycle_start_idx++;
            }

            int cycle_min = curr;
            for (size_t j = cycle_start_idx; j < path.size(); ++j) {
                cycle_min = std::min(cycle_min, path[j]);
            }
            for (size_t j = cycle_start_idx; j < path.size(); ++j) {
                final_dest[path[j]] = cycle_min;
                visited[path[j]] = true;
            }
        }

        for (int j = path.size() - 1; j >= 0; --j) {
            if (!visited[path[j]]) {
                final_dest[path[j]] = std::min(path[j], final_dest[p[path[j]]]);
                visited[path[j]] = true;
            }
        }
    }

    roots[0] = 0;
    tree[0] = {0, 0, 0};
    for (int i = 1; i <= N; ++i) {
        roots[i] = update(roots[i-1], 1, N, final_dest[i]);
    }

    for (int q = 0; q < Q; ++q) {
        int L, R;
        std::cin >> L >> R;

        long long S = R - L + 1;
        long long k = (S + 1) / 2;

        int X_b = -1;
        int low = 1, high = N;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (count_le(roots[L-1], roots[R], 1, N, mid) >= k) {
                X_b = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long long c_b = count_le(roots[L-1], roots[R], 1, N, X_b);
        long long c_a = (X_b > 1) ? count_le(roots[L-1], roots[R], 1, N, X_b - 1) : 0;
        
        long long diff_b = std::abs(2 * c_b - S);
        long long diff_a = std::abs(2 * c_a - S);

        if (diff_a <= diff_b) {
            if (c_a == 0) {
                std::cout << 1 << "\n";
            } else {
                std::cout << query_kth(roots[L-1], roots[R], 1, N, c_a) << "\n";
            }
        } else {
            std::cout << X_b << "\n";
        }
    }

    return 0;
}
