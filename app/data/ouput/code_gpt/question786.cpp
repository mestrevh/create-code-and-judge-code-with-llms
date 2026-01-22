/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int left, right;
};

vector<Node> tree;

int height(int node) {
    if (node == -1) return 0;
    return 1 + max(height(tree[node].left), height(tree[node].right));
}

int main() {
    int n, k, r;
    cin >> n >> k >> r;
    tree.resize(n);
    for (int i = 0; i < k; ++i) {
        int s, l, r;
        cin >> s >> l >> r;
        tree[s] = {l, r};
    }
    
    cout << height(r) << endl;
    return 0;
}
