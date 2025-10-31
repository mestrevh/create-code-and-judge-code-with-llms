/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void insert(Node* &root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return;
    }
    if (key < root->key) {
        insert(root->left, key);
    } else {
        insert(root->right, key);
    }
}

void printTree(Node* root) {
    if (root == nullptr) {
        std::cout << "()";
        return;
    }
    std::cout << "( " << root->key << "  ";
    printTree(root->left);
    std::cout << "  ";
    printTree(root->right);
    std::cout << " )";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* root = nullptr;
    int x;

    while (std::cin >> x) {
        insert(root, x);
        std::cout << "----\n";
        std::cout << "Adicionando " << x << "\n";
        std::cout << "   ";
        printTree(root);
        std::cout << " \n";
        std::cout << "----\n";
    }

    return 0;
}
