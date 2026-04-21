/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    int height;
    Node *left, *right;
    Node(int v) : val(v), height(1), left(nullptr), right(nullptr) {}
};

int getH(Node* n) {
    return n ? n->height : 0;
}

void updateH(Node* n) {
    if (n) n->height = 1 + max(getH(n->left), getH(n->right));
}

int getBF(Node* n) {
    return n ? getH(n->left) - getH(n->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateH(y);
    updateH(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateH(x);
    updateH(y);
    return y;
}

Node* insertBST(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->val) node->left = insertBST(node->left, val);
    else node->right = insertBST(node->right, val);
    updateH(node);
    return node;
}

bool isBalanced(Node* n) {
    if (!n) return true;
    int bf = getBF(n);
    if (bf > 1 || bf < -1) return false;
    return isBalanced(n->left) && isBalanced(n->right);
}

Node* rebalanceTree(Node* n) {
    if (!n) return nullptr;
    n->left = rebalanceTree(n->left);
    n->right = rebalanceTree(n->right);
    updateH(n);
    int bf = getBF(n);
    if (bf > 1) {
        if (getBF(n->left) < 0) n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    if (bf < -1) {
        if (getBF(n->right) > 0) n->right = rotateRight(n->right);
        return rotateLeft(n);
    }
    return n;
}

void printTree(Node* n) {
    if (!n) {
        cout << "()";
        return;
    }
    cout << "( " << n->val << "  ";
    printTree(n->left);
    cout << "  ";
    printTree(n->right);
    cout << " )";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int X;
    Node* root = nullptr;
    while (cin >> X) {
        cout << "----" << endl;
        cout << "Adicionando " << X << endl;
        root = insertBST(root, X);
        if (isBalanced(root)) {
            cout << "Continuou AVL..." << endl;
            cout << "   ";
            printTree(root);
            cout << " " << endl;
        } else {
            cout << "Antes de ajustar balanceamento..." << endl;
            cout << "   ";
            printTree(root);
            cout << " " << endl;
            root = rebalanceTree(root);
            cout << "Depois de ajustar balanceamento..." << endl;
            cout << "   ";
            printTree(root);
            cout << " " << endl;
        }
    }
    cout << "----" << endl;
    return 0;
}