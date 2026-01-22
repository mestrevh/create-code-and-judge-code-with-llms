/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

std::string postorder_str;
int post_idx;

Node* buildTree() {
    if (post_idx < 0) {
        return nullptr;
    }
    char val = postorder_str[post_idx];
    post_idx--;
    Node* node = new Node(val);
    if (val != '*') {
        node->right = buildTree();
        node->left = buildTree();
    }
    return node;
}

void inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    if (node->data != '*') {
        std::cout << node->data;
    }
    inOrder(node->right);
}

void printTree(Node* node, int depth) {
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < depth; ++i) {
        std::cout << " ";
    }
    std::cout << node->data << std::endl;
    printTree(node->left, depth + 1);
    printTree(node->right, depth + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::getline(std::cin, postorder_str);
    post_idx = postorder_str.length() - 1;
    Node* root = buildTree();
    std::cout << "Mensagem decodificada: ";
    inOrder(root);
    std::cout << std::endl;
    std::cout << "Arvore construida:" << std::endl;
    printTree(root, 0);
    return 0;
}
