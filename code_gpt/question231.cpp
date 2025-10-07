/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* parseTree(std::istringstream &iss) {
    char ch;
    iss >> ch;
    if (ch == '(') {
        int value;
        iss >> value;
        Node* root = new Node(value);
        root->left = parseTree(iss);
        root->right = parseTree(iss);
        iss >> ch; // Expecting ')'
        return root;
    }
    return nullptr;
}

bool hasPathSum(Node* root, int sum) {
    if (!root) return sum == 0;
    sum -= root->value;
    if (!root->left && !root->right) return sum == 0;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

void clearTree(Node* root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int main() {
    int target;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        iss >> target;
        if (target == -1000) break;
        
        Node* tree = parseTree(iss);
        if (hasPathSum(tree, target)) std::cout << "sim\n";
        else std::cout << "nao\n";
        
        clearTree(tree);
    }
    return 0;
}
