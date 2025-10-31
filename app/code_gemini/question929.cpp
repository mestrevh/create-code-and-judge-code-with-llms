/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<std::pair<int, int>> tree(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tree[i].first >> tree[i].second;
    }

    std::vector<bool> is_leaf(n);
    for (int i = 0; i < n; ++i) {
        is_leaf[i] = (tree[i].first == -1 && tree[i].second == -1);
    }

    std::set<int> parents_of_leaves;
    for (int i = 0; i < n; ++i) {
        int left_child = tree[i].first;
        int right_child = tree[i].second;

        if ((left_child != -1 && is_leaf[left_child]) || (right_child != -1 && is_leaf[right_child])) {
            parents_of_leaves.insert(i);
        }
    }

    for (const auto& parent : parents_of_leaves) {
        std::cout << parent << "\n";
    }

    return 0;
}
