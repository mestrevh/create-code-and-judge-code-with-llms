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

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void printTree(Node* root) {
    if (!root) {
        cout << "()";
        return;
    }
    cout << "( " << root->val << "  ";
    printTree(root->left);
    cout << "  ";
    printTree(root->right);
    cout << " )";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    Node* root = nullptr;
    bool first = true;

    while (cin >> x) {
        if (first) {
            cout << "----" << "\n";
            first = false;
        }
        root = insert(root, x);
        cout << "Adicionando " << x << "\n";
        cout << "   ";
        printTree(root);
        cout << " \n";
        cout << "----" << "\n";
    }

    return 0;
}