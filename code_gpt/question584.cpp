/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    int add(int k) {
        root = insert(root, k);
        return getHeight(root, k);
    }

    int del(int k) {
        if (!find(k)) return 0;
        root = remove(root, k);
        return getHeight(root, k);
    }

    int qry(int k) {
        return getHeight(root, k);
    }

    pair<int, int> interval(int l, int r) {
        vector<int> keys;
        rangeKeys(root, keys, l, r);
        if (keys.empty()) return {-1, -1};
        return {keys.front(), keys.back()};
    }

private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);
        updateHeight(node);
        return node;
    }

    Node* remove(Node* node, int key) {
        if (!node) return node;
        if (key < node->key) node->left = remove(node->left, key);
        else if (key > node->key) node->right = remove(node->right, key);
        else {
            if (!node->left) return node->right;
            else if (!node->right) return node->left;

            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
        updateHeight(node);
        return node;
    }

    void updateHeight(Node* node) {
        if (!node) return;
        node->height = 1 + max(height(node->left), height(node->right));
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    Node* minValueNode(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    int getHeight(Node* node, int key) {
        while (node) {
            if (key < node->key) node = node->left;
            else if (key > node->key) node = node->right;
            else return node->height;
        }
        return 0;
    }

    void rangeKeys(Node* node, vector<int>& keys, int l, int r) {
        if (!node) return;
        if (node->key > l) rangeKeys(node->left, keys, l, r);
        if (node->key >= l && node->key <= r) keys.push_back(node->key);
        if (node->key < r) rangeKeys(node->right, keys, l, r);
    }

    bool find(int key) {
        Node* node = root;
        while (node) {
            if (key < node->key) node = node->left;
            else if (key > node->key) node = node->right;
            else return true;
        }
        return false;
    }
};

int main() {
    int N, M, seedX, A, C;
    cin >> N >> M >> seedX >> A >> C;

    BST tree;
    map<int, bool> exists;
    for (int i = 0; i < N; ++i) {
        if (!exists[seedX]) {
            tree.add(seedX);
            exists[seedX] = true;
        }
        seedX = (A * seedX + C) % M;
    }

    string cmd;
    int k, l, r, opNum = 0;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            cin >> k;
            cout << opNum++ << " " << tree.add(k) << endl;
        }
        else if (cmd == "DEL") {
            cin >> k;
            cout << opNum++ << " " << tree.del(k) << endl;
        }
        else if (cmd == "QRY") {
            cin >> k;
            cout << opNum++ << " " << tree.qry(k) << endl;
        }
        else if (cmd == "INT") {
            cin >> l >> r;
            auto result = tree.interval(l, r);
            if (result.first != -1)
                cout << opNum++ << " " << result.first << " " << result.second << endl;
        }
    }
    return 0;
}
