/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Node {
    long long sum;
    int min_val;
};

std::vector<int> initial_values;
std::vector<Node> tree;

Node merge(const Node& left, const Node& right) {
    return {left.sum + right.sum, std::min(left.min_val, right.min_val)};
}

void build(int node_idx, int start, int end) {
    if (start == end) {
        tree[node_idx] = {(long long)initial_values[start], initial_values[start]};
    } else {
        int mid = start + (end - start) / 2;
        build(2 * node_idx, start, mid);
        build(2 * node_idx + 1, mid + 1, end);
        tree[node_idx] = merge(tree[2 * node_idx], tree[2 * node_idx + 1]);
    }
}

void update(int node_idx, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node_idx] = {(long long)val, val};
    } else {
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node_idx, start, mid, idx, val);
        } else {
            update(2 * node_idx + 1, mid + 1, end, idx, val);
        }
        tree[node_idx] = merge(tree[2 * node_idx], tree[2 * node_idx + 1]);
    }
}

Node query(int node_idx, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {0, std::numeric_limits<int>::max()};
    }
    if (l <= start && end <= r) {
        return tree[node_idx];
    }
    int mid = start + (end - start) / 2;
    Node p1 = query(2 * node_idx, start, mid, l, r);
    Node p2 = query(2 * node_idx + 1, mid + 1, end, l, r);
    return merge(p1, p2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    initial_values.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> initial_values[i];
    }

    tree.resize(4 * n);
    build(1, 0, n - 1);

    int q;
    std::cin >> q;

    while (q--) {
        char type;
        std::cin >> type;
        if (type == 'Q') {
            int l, r;
            std::cin >> l >> r;
            Node result = query(1, 0, n - 1, l, r);
            std::cout << result.sum << " " << result.min_val << "\n";
        } else {
            int p, v;
            std::cin >> p >> v;
            update(1, 0, n - 1, p, v);
        }
    }

    return 0;
}
