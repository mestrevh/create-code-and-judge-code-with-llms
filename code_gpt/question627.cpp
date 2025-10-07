/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

struct Node {
    int value, height;
    Node *left, *right;
    Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
public:
    Node* root;
    AVLTree() : root(nullptr) {}

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int balanceFactor(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    void fixHeight(Node* n) {
        n->height = std::max(height(n->left), height(n->right)) + 1;
    }

    Node* rotateRight(Node* n) {
        Node* newRoot = n->left;
        n->left = newRoot->right;
        newRoot->right = n;
        fixHeight(n);
        fixHeight(newRoot);
        return newRoot;
    }

    Node* rotateLeft(Node* n) {
        Node* newRoot = n->right;
        n->right = newRoot->left;
        newRoot->left = n;
        fixHeight(n);
        fixHeight(newRoot);
        return newRoot;
    }

    Node* balance(Node* n) {
        fixHeight(n);
        if (balanceFactor(n) == 2) {
            if (balanceFactor(n->left) < 0)
                n->left = rotateLeft(n->left);
            return rotateRight(n);
        }
        if (balanceFactor(n) == -2) {
            if (balanceFactor(n->right) > 0)
                n->right = rotateRight(n->right);
            return rotateLeft(n);
        }
        return n;
    }

    Node* insert(Node* n, int value) {
        if (!n) return new Node(value);
        if (value < n->value)
            n->left = insert(n->left, value);
        else
            n->right = insert(n->right, value);
        return balance(n);
    }

    void print(Node* n) {
        if (!n) {
            std::cout << "()";
            return;
        }
        std::cout << "(" << n->value << " ";
        print(n->left);
        std::cout << " ";
        print(n->right);
        std::cout << ")";
    }

    void insert(int value) {
        std::cout << "----\nAdicionando " << value << "\n";
        Node* before = root;
        root = insert(root, value);
        if (root != before) {
            std::cout << "Antes de ajustar balanceamento...\n";
            print(before);
            std::cout << "\nDepois de ajustar balanceamento...\n";
            print(root);
        } else {
            std::cout << "Antes de ajustar balanceamento...\n";
            print(root);
            std::cout << "\nDepois de ajustar balanceamento...\n";
            print(root);
        }
        std::cout << "\n";
    }
};

int main() {
    AVLTree tree;
    int value;
    while (std::cin >> value) {
        tree.insert(value);
    }
    return 0;
}
