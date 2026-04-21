/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int v) {
    if (!root) {
        root = new Node(v);
        return;
    }
    if (v < root->val) {
        insert(root->left, v);
    } else {
        insert(root->right, v);
    }
}

void pre_order(Node* root) {
    if (!root) return;
    cout << " " << root->val;
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node* root) {
    if (!root) return;
    in_order(root->left);
    cout << " " << root->val;
    in_order(root->right);
}

void post_order(Node* root) {
    if (!root) return;
    post_order(root->left);
    post_order(root->right);
    cout << " " << root->val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        insert(root, val);
    }

    cout << "Pre order :";
    pre_order(root);
    cout << "\n";

    cout << "In order  :";
    in_order(root);
    cout << "\n";

    cout << "Post order:";
    post_order(root);
    cout << "\n";

    return 0;
}