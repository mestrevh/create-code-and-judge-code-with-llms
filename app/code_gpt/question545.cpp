/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node *root;

    BST() : root(nullptr) {}

    bool add(int k) {
        if (!root) {
            root = new Node(k);
            return true;
        }
        return addRec(root, k);
    }

    bool addRec(Node *node, int k) {
        if (k < node->key) {
            if (!node->left) {
                node->left = new Node(k);
                return true;
            }
            return addRec(node->left, k);
        } else if (k > node->key) {
            if (!node->right) {
                node->right = new Node(k);
                return true;
            }
            return addRec(node->right, k);
        }
        return false;
    }

    bool del(int k) {
        return delRec(root, k);
    }

    bool delRec(Node *&node, int k) {
        if (!node) return false;
        if (k < node->key) return delRec(node->left, k);
        if (k > node->key) return delRec(node->right, k);
        if (!node->left) {
            Node *temp = node;
            node = node->right;
            delete temp;
            return true;
        }
        if (!node->right) {
            Node *temp = node;
            node = node->left;
            delete temp;
            return true;
        }
        Node *temp = findMin(node->right);
        node->key = temp->key;
        return delRec(node->right, temp->key);
    }

    Node* findMin(Node *node) {
        while (node && node->left) node = node->left;
        return node;
    }

    int countInRange(int a, int b) {
        return countInRangeRec(root, a, b);
    }

    int countInRangeRec(Node *node, int a, int b) {
        if (!node) return 0;
        if (node->key < a) return countInRangeRec(node->right, a, b);
        if (node->key > b) return countInRangeRec(node->left, a, b);
        return 1 + countInRangeRec(node->left, a, b) + countInRangeRec(node->right, a, b);
    }

    int secondLargest() {
        return secondLargestRec(root);
    }

    int secondLargestRec(Node *node) {
        if (!node) return -1;
        if (node->right) {
            Node *temp = node->right;
            while (temp->right) temp = temp->right;
            if (temp->left) return findMax(temp->left);
            return node->key;
        }
        return -1;
    }

    int findMax(Node *node) {
        while (node->right) node = node->right;
        return node->key;
    }
};

void bst_init(BST &tree, const std::vector<int> &X, int a, int b) {
    if (a > b) return;
    int c = (a + b) / 2;
    tree.add(X[c]);
    bst_init(tree, X, a, c - 1);
    bst_init(tree, X, c + 1, b);
}

int main() {
    int N, seedY, z, w, modY, seedX, modX;
    std::cin >> N >> seedY >> z >> w >> modY >> seedX >> modX;
    
    std::vector<int> Y(N), X(N);
    Y[0] = seedY;
    X[0] = seedX;
    
    for (int i = 1; i < N; ++i) {
        Y[i] = (Y[i - 1] * z + w) % modY;
        X[i] = X[i - 1] + 1 + (Y[i - 1] % modX);
    }

    BST tree;
    bst_init(tree, X, 0, N - 1);

    std::string command;
    while (std::cin >> command) {
        if (command == "ADD") {
            int k;
            std::cin >> k;
            std::cout << tree.add(k) << std::endl;
        } else if (command == "DEL") {
            int k;
            std::cin >> k;
            std::cout << tree.del(k) << std::endl;
        } else if (command == "INT") {
            int a, b;
            std::cin >> a >> b;
            std::cout << tree.countInRange(a, b) << std::endl;
        } else if (command == "SGE") {
            std::cout << tree.secondLargest() << std::endl;
        }
    }
    
    return 0;
}
