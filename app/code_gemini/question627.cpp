/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(0) {}
};

int height(Node* n) {
    return (n == nullptr) ? -1 : n->height;
}

void updateHeight(Node* n) {
    if (n != nullptr) {
        n->height = 1 + std::max(height(n->left), height(n->right));
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

int getBalance(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node* avl_insert(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = avl_insert(node->left, key);
    } else if (key > node->key) {
        node->right = avl_insert(node->right, key);
    } else {
        return node;
    }

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1) { // Left Heavy
        if (getBalance(node->left) < 0) { // Left Right Case
            node->left = leftRotate(node->left);
        }
        return rightRotate(node); // Left Left Case
    }

    if (balance < -1) { // Right Heavy
        if (getBalance(node->right) > 0) { // Right Left Case
            node->right = rightRotate(node->right);
        }
        return leftRotate(node); // Right Right Case
    }

    return node;
}

Node* bst_insert_and_update_heights(Node* node, int key) {
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = bst_insert_and_update_heights(node->left, key);
    } else if (key > node->key) {
        node->right = bst_insert_and_update_heights(node->right, key);
    } else {
        return node;
    }

    updateHeight(node);
    return node;
}


Node* clone_tree(const Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node* new_node = new Node(node->key);
    new_node->height = node->height;
    new_node->left = clone_tree(node->left);
    new_node->right = clone_tree(node->right);
    return new_node;
}

void delete_tree(Node* node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

void print_tree(Node* node) {
    if (node == nullptr) {
        std::cout << "()";
        return;
    }
    std::cout << "( " << node->key << " ";
    print_tree(node->left);
    std::cout << " ";
    print_tree(node->right);
    std::cout << " )";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* root = nullptr;
    int x;

    while (std::cin >> x) {
        std::cout << "----\n";
        std::cout << "Adicionando " << x << "\n";

        Node* before_root = clone_tree(root);
        before_root = bst_insert_and_update_heights(before_root, x);
        
        std::cout << "Antes de ajustar balanceamento...\n";
        print_tree(before_root);
        std::cout << "\n";
        
        delete_tree(before_root);

        root = avl_insert(root, x);

        std::cout << "Depos de ajustar balanceamento...\n";
        print_tree(root);
        std::cout << "\n";
    }
    
    std::cout << "----\n";

    delete_tree(root);

    return 0;
}
