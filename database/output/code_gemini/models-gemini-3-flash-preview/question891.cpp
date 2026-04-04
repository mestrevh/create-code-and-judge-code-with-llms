/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    long long val;
    Node *left, *right;
    Node(long long v) : val(v), left(nullptr), right(nullptr) {}
};

Node* readTree() {
    char c;
    if (!(cin >> c)) return nullptr; 
    if (cin.peek() == ')') {
        cin >> c; 
        return nullptr;
    }
    long long val;
    if (!(cin >> val)) return nullptr;
    Node* root = new Node(val);
    if (cin.peek() == ':') {
        cin >> c; 
        root->left = readTree();
        root->right = readTree();
    }
    cin >> c; 
    return root;
}

struct Result {
    bool isBST;
    long long mn, mx;
};

Result checkBST(Node* root) {
    bool isBST = true;
    long long mn = root->val;
    long long mx = root->val;
    if (root->left) {
        Result L = checkBST(root->left);
        if (!L.isBST || L.mx >= root->val) isBST = false;
        mn = min(mn, L.mn);
        mx = max(mx, L.mx);
    }
    if (root->right) {
        Result R = checkBST(root->right);
        if (!R.isBST || R.mn <= root->val) isBST = false;
        mn = min(mn, R.mn);
        mx = max(mx, R.mx);
    }
    return {isBST, mn, mx};
}

Node* insert(Node* root, long long val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

Node* remove(Node* root, long long val) {
    if (!root) return nullptr;
    if (val < root->val) root->left = remove(root->left, val);
    else if (val > root->val) root->right = remove(root->right, val);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = root->right;
        while (succ->left) succ = succ->left;
        root->val = succ->val;
        root->right = remove(root->right, succ->val);
    }
    return root;
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << "\n";
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* gabi = nullptr;
    while (cin >> ws && cin.peek() != EOF) {
        Node* t = readTree();
        if (t) {
            long long rval = t->val;
            Result res = checkBST(t);
            if (res.isBST) {
                gabi = insert(gabi, res.mn);
            } else {
                gabi = remove(gabi, rval);
            }
            freeTree(t);
        }
    }
    postOrder(gabi);
    return 0;
}