/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>

struct Node {
    int even;
    int odd;
};

std::vector<int> arr;
std::vector<Node> tree;
int N;

Node merge(const Node& left, const Node& right) {
    return {left.even + right.even, left.odd + right.odd};
}

void build(int node, int start, int end) {
    if (start == end) {
        if (arr[start] % 2 == 0) {
            tree[node] = {1, 0};
        } else {
            tree[node] = {0, 1};
        }
        return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        if (val % 2 == 0) {
            tree[node] = {1, 0};
        } else {
            tree[node] = {0, 1};
        }
        return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {0, 0};
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    Node p1 = query(2 * node, start, mid, l, r);
    Node p2 = query(2 * node + 1, mid + 1, end, l, r);
    return merge(p1, p2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

    arr.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> arr[i];
    }

    tree.resize(4 * N);
    build(1, 1, N);

    int Q;
    std::cin >> Q;

    while (Q--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int i, x;
            std::cin >> i >> x;
            update(1, 1, N, i, x);
        } else if (type == 1) {
            int l, r;
            std::cin >> l >> r;
            Node result = query(1, 1, N, l, r);
            std::cout << result.even << "\n";
        } else {
            int l, r;
            std::cin >> l >> r;
            Node result = query(1, 1, N, l, r);
            std::cout << result.odd << "\n";
        }
    }

    return 0;
}
