/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <climits>
#include <cctype>

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

std::string s;
int pos;

Node* build_tree() {
    pos++; 
    if (pos >= s.length() || s[pos] == ')') {
        pos++; 
        return nullptr;
    }

    int val = 0;
    bool negative = false;
    if (s[pos] == '-') {
        negative = true;
        pos++;
    }
    while (pos < s.length() && isdigit(s[pos])) {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    if (negative) {
        val = -val;
    }

    Node* node = new Node(val);
    node->left = build_tree();
    node->right = build_tree();
    
    pos++;

    return node;
}

bool is_valid_bst(Node* node, long long min_val, long long max_val) {
    if (node == nullptr) {
        return true;
    }

    if (node->val <= min_val || node->val >= max_val) {
        return false;
    }

    return is_valid_bst(node->left, min_val, node->val) &&
           is_valid_bst(node->right, node->val, max_val);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::getline(std::cin, s);

    if (s.empty() || s == "()") {
        std::cout << "VERDADEIRO" << std::endl;
        return 0;
    }

    pos = 0;
    Node* root = build_tree();

    if (is_valid_bst(root, LLONG_MIN, LLONG_MAX)) {
        std::cout << "VERDADEIRO" << std::endl;
    } else {
        std::cout << "FALSO" << std::endl;
    }

    return 0;
}
