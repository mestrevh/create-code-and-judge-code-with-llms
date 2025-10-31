/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> tree;

int calculateHeight(int node) {
    if (node == -1) {
        return 0;
    }

    int left_height = calculateHeight(tree[node].first);
    int right_height = calculateHeight(tree[node].second);

    return 1 + std::max(left_height, right_height);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, r;
    std::cin >> n >> k >> r;

    tree.assign(n, {-1, -1});

    for (int i = 0; i < k; ++i) {
        int s, l, r_child;
        std::cin >> s >> l >> r_child;
        tree[s] = {l, r_child};
    }

    int height = calculateHeight(r);
    std::cout << height << std::endl;

    return 0;
}
