/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value, left, right;
};

bool hasPathSum(const vector<Node>& tree, int nodeIndex, int currentSum, int targetSum) {
    if (nodeIndex == -1) return false;
    
    currentSum += tree[nodeIndex].value;
    
    if (tree[nodeIndex].left == -1 && tree[nodeIndex].right == -1) {
        return currentSum == targetSum;
    }

    return hasPathSum(tree, tree[nodeIndex].left, currentSum, targetSum) ||
           hasPathSum(tree, tree[nodeIndex].right, currentSum, targetSum);
}

int main() {
    int N;
    cin >> N;
    
    vector<Node> tree(N);
    for (int i = 0; i < N; ++i) {
        cin >> tree[i].value >> tree[i].left >> tree[i].right;
    }

    int targetSum;
    cin >> targetSum;
    
    if (hasPathSum(tree, 0, 0, targetSum)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }
    
    return 0;
}
