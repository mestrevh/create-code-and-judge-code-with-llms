/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* build_tree(const std::string& s, int& pos) {
    while (pos < s.length() && isspace(s[pos])) {
        pos++;
    }

    if (pos >= s.length() || s[pos] != '(') {
        return nullptr;
    }
    pos++;

    while (pos < s.length() && isspace(s[pos])) {
        pos++;
    }

    if (pos < s.length() && s[pos] == ')') {
        pos++;
        return nullptr;
    }

    int val = 0;
    int sign = 1;
    if (s[pos] == '-') {
        sign = -1;
        pos++;
    }
    while (pos < s.length() && isdigit(s[pos])) {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    val *= sign;

    Node* node = new Node(val);

    node->left = build_tree(s, pos);
    node->right = build_tree(s, pos);

    while (pos < s.length() && isspace(s[pos])) {
        pos++;
    }
    
    if (pos < s.length() && s[pos] == ')') {
        pos++;
    }

    return node;
}

int find_depth(Node* node, int target, int current_depth) {
    if (node == nullptr) {
        return -1;
    }
    if (node->value == target) {
        return current_depth;
    }
    
    int left_result = find_depth(node->left, target, current_depth + 1);
    if (left_result != -1) {
        return left_result;
    }
    
    return find_depth(node->right, target, current_depth + 1);
}

void delete_tree(Node* node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string tree_str;
    std::getline(std::cin, tree_str);
    
    int n_to_find;
    std::cin >> n_to_find;

    int pos = 0;
    Node* root = build_tree(tree_str, pos);

    int depth = find_depth(root, n_to_find, 0);

    if (depth != -1) {
        std::cout << "ESTA NA ARVORE\n";
        std::cout << depth << "\n";
    } else {
        std::cout << "NAO ESTA NA ARVORE\n";
        std::cout << -1 << "\n";
    }
    
    delete_tree(root);

    return 0;
}
