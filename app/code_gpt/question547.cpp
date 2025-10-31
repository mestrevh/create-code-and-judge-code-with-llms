/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cstdlib>

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(const std::string& str, int& pos) {
    if (pos >= str.size() || str[pos] == ')') return nullptr;
    
    int num = 0;
    while (pos < str.size() && std::isdigit(str[pos])) {
        num = num * 10 + (str[pos] - '0');
        pos++;
    }
    
    Node* node = new Node(num);
    pos++;  // Skip '('
    node->left = buildTree(str, pos);
    pos++;  // Skip ')'
    pos++;  // Skip '('
    node->right = buildTree(str, pos);
    pos++;  // Skip ')'
    
    return node;
}

bool findNode(Node* root, int N, int depth, int& resultDepth) {
    if (!root) return false;
    if (root->value == N) {
        resultDepth = depth;
        return true;
    }
    return findNode(root->left, N, depth + 1, resultDepth) || findNode(root->right, N, depth + 1, resultDepth);
}

int main() {
    std::string input = "(12(7(3()())(10()(11()())))(23(17()())(31()())))";
    int N = 11; // Altere aqui para testar outras entradas

    int pos = 1;
    Node* root = buildTree(input, pos);
    
    int depth = -1;
    if (findNode(root, N, 0, depth)) {
        std::cout << "ESTA NA ARVORE\n" << depth << "\n";
    } else {
        std::cout << "NAO ESTA NA ARVORE\n-1\n";
    }

    return 0;
}
