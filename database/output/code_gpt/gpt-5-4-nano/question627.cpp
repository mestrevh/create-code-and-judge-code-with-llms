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
    int h;
    Node(int v) : val(v), left(nullptr), right(nullptr), h(1) {}
};

static int height(Node* n) {
    return n ? n->h : 0;
}

static void update(Node* n) {
    if (!n) return;
    n->h = 1 + max(height(n->left), height(n->right));
}

static int balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

static Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}

static Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}

static Node* insertAVL(Node* root, int key, bool &didRotate) {
    if (!root) return new Node(key);

    if (key < root->val) root->left = insertAVL(root->left, key, didRotate);
    else root->right = insertAVL(root->right, key, didRotate);

    update(root);

    int bf = balanceFactor(root);

    if (bf > 1) {
        if (key < root->left->val) {
            didRotate = true;
            return rotateRight(root);
        } else {
            didRotate = true;
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (bf < -1) {
        if (key > root->right->val) {
            didRotate = true;
            return rotateLeft(root);
        } else {
            didRotate = true;
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}

static void printTree(Node* n, ostream &out) {
    if (!n) return;
    out << "( " << n->val << " ";
    if (n->left) printTree(n->left, out);
    else out << "( )";
    out << " ";
    if (n->right) printTree(n->right, out);
    else out << "( )";
    out << " )";
}

static void printTreeFormat(Node* n, ostream &out) {
    if (!n) {
        out << "( )";
        return;
    }
    out << "( " << n->val << " ";
    if (n->left) printTreeFormat(n->left, out);
    else out << "( () () )";
    out << " ";
    if (n->right) printTreeFormat(n->right, out);
    else out << "( () () )";
    out << " )";
}

static void printTreeParens(Node* n, ostream &out) {
    if (!n) return;
    function<void(Node*)> dfs = [&](Node* u) {
        if (!u) return;
    };
    out << "( " << n->val << " ";
    if (n->left) {
        out << "";
        function<void(Node*)> rec = [&](Node* cur) {
            out << "( " << cur->val << " ";
            if (cur->left) rec(cur->left);
            else out << "( )";
            out << " ";
            if (cur->right) rec(cur->right);
            else out << "( )";
            out << " )";
        };
        rec(n->left);
    } else {
        out << "( )";
    }
    out << " ";
    if (n->right) {
        function<void(Node*)> rec = [&](Node* cur) {
            out << "( " << cur->val << " ";
            if (cur->left) rec(cur->left);
            else out << "( )";
            out << " ";
            if (cur->right) rec(cur->right);
            else out << "( )";
            out << " )";
        };
        rec(n->right);
    } else {
        out << "( )";
    }
    out << " )";
}

static void printTreeCorrect(Node* n, ostream &out) {
    if (!n) {
        out << "( )";
        return;
    }
    out << "( " << n->val << " ";
    if (n->left) printTreeCorrect(n->left, out);
    else out << "( )";
    out << " ";
    if (n->right) printTreeCorrect(n->right, out);
    else out << "( )";
    out << " )";
}

static void deleteTree(Node* n) {
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int x;
    while (cin >> x) nums.push_back(x);

    Node* root = nullptr;

    for (int v : nums) {
        cout << "----\nAdicionando " << v << "\n";

        bool didRotate = false;

        if (!root) {
            root = new Node(v);
            cout << "Continuou AVL...\n";
            cout << "   ( " << root->val << "  ()  () ) \n";
            continue;
        }

        bool dummy = false;
        Node* beforeRoot = root;
        Node* afterInsertRoot = insertAVL(root, v, didRotate);

        if (didRotate) {
            cout << "Antes de ajustar balanceamento...\n";
            cout << "   ";
            printTreeCorrect(beforeRoot, cout);
            cout << " \n";
            cout << "Depois de ajustar balanceamento...\n";
            cout << "   ";
            printTreeCorrect(afterInsertRoot, cout);
            cout << " \n";
        } else {
            cout << "Continuou AVL...\n";
            cout << "   ";
            printTreeCorrect(afterInsertRoot, cout);
            cout << " \n";
        }

        root = afterInsertRoot;
    }

    deleteTree(root);
    return 0;
}