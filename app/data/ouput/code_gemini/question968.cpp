/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

struct Node {
    int value;
    int left;
    int right;
};

std::vector<Node> tree;

bool hasPathSum(int nodeIndex, int remainingSum) {
    if (nodeIndex == -1) {
        return false;
    }

    remainingSum -= tree[nodeIndex].value;

    bool isLeaf = (tree[nodeIndex].left == -1 && tree[nodeIndex].right == -1);

    if (isLeaf) {
        return (remainingSum == 0);
    }

    return hasPathSum(tree[nodeIndex].left, remainingSum) ||
           hasPathSum(tree[nodeIndex].right, remainingSum);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        int s;
        std::cin >> s;
        std::cout << "NAO\n";
        return 0;
    }
    
    tree.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tree[i].value >> tree[i].left >> tree[i].right;
    }

    int s;
    std::cin >> s;

    if (hasPathSum(0, s)) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }

    return 0;
}
