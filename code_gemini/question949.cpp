/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

struct Node {
    int value;
    int left;
    int right;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tree[i].value >> tree[i].left >> tree[i].right;
    }

    std::queue<int> q;
    q.push(0);

    int level_num = 1;

    while (!q.empty()) {
        int level_size = q.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int i = 0; i < level_size; ++i) {
            int current_idx = q.front();
            q.pop();

            Node& current_node = tree[current_idx];

            min_val = std::min(min_val, current_node.value);
            max_val = std::max(max_val, current_node.value);

            if (current_node.left != -1) {
                q.push(current_node.left);
            }
            if (current_node.right != -1) {
                q.push(current_node.right);
            }
        }

        std::cout << "Nivel " << level_num << ": Maior = " << max_val << ", Menor = " << min_val << '\n';
        level_num++;
    }

    return 0;
}
