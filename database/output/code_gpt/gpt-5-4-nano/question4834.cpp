/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

void insertNode(Node*& root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    if (x < root->val) insertNode(root->left, x);
    else insertNode(root->right, x);
}

void preorder(Node* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}

void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

void postorder(Node* root, vector<int>& out) {
    if (!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->val);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertNode(root, x);
    }

    vector<int> a, b, c;
    preorder(root, a);
    inorder(root, b);
    postorder(root, c);

    cout << "Pre order :";
    for (int x : a) cout << ' ' << x;
    cout << "\n";

    cout << "In order  :";
    for (int x : b) cout << ' ' << x;
    cout << "\n";

    cout << "Post order:";
    for (int x : c) cout << ' ' << x;
    cout << "\n";

    deleteTree(root);
    return 0;
}