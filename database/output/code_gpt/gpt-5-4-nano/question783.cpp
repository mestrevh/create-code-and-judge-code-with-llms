/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(long long v) : val(v), left(nullptr), right(nullptr) {}
};

static string formatTree(Node* n) {
    if (!n) return "()";
    string s;
    s += "( " + to_string(n->val) + " ";
    s += formatTree(n->left) + " ";
    s += formatTree(n->right) + " )";
    return s;
}

static Node* insertBST(Node* root, long long x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> nums;
    long long x;
    while (cin >> x) nums.push_back(x);

    Node* root = nullptr;
    for (long long v : nums) {
        root = insertBST(root, v);
        cout << "----\n";
        cout << "Adicionando " << v << "\n";
        cout << "   " << formatTree(root) << " \n";
    }

    return 0;
}