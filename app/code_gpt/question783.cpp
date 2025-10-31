/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <string>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
        printTree(root);
    }

private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void printTree(Node* node) {
        if (!node) {
            std::cout << "()";
            return;
        }
        std::cout << "( " << node->value << " ";
        printTree(node->left);
        std::cout << " ";
        printTree(node->right);
        std::cout << " )";
    }
};

int main() {
    BST tree;
    std::string line;
    getline(std::cin, line);
    std::istringstream iss(line);
    int value;

    while (iss >> value) {
        std::cout << "----" << std::endl;
        std::cout << "Adicionando " << value << std::endl;
        tree.insert(value);
        std::cout << std::endl;
    }

    return 0;
}
