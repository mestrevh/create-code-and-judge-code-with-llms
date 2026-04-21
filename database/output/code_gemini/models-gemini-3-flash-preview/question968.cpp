/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    int left;
    int right;
};

bool findPath(int u, long long current_sum, long long target, const vector<Node>& tree) {
    if (u == -1) return false;
    
    current_sum += tree[u].val;
    
    if (tree[u].left == -1 && tree[u].right == -1) {
        return current_sum == target;
    }
    
    if (tree[u].left != -1) {
        if (findPath(tree[u].left, current_sum, target, tree)) return true;
    }
    
    if (tree[u].right != -1) {
        if (findPath(tree[u].right, current_sum, target, tree)) return true;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    if (n <= 0) {
        long long target;
        cin >> target;
        cout << "NAO" << endl;
        return 0;
    }
    
    vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
    }
    
    long long target;
    cin >> target;
    
    if (findPath(0, 0, target, tree)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }
    
    return 0;
}