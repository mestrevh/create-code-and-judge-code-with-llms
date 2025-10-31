/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(const string& s, int& index) {
    if (index >= s.size() || s[index] == ')') {
        return nullptr;
    }
    
    int num = 0;
    while (isdigit(s[index])) {
        num = num * 10 + (s[index] - '0');
        index++;
    }
    
    Node* node = new Node(num);
    
    if (s[index] == '(') {
        index++;
        node->left = buildTree(s, index);
        index++;
        node->right = buildTree(s, index);
        index++;
    }
    
    return node;
}

bool isBST(Node* node, int minValue, int maxValue) {
    if (!node) return true;
    if (node->value <= minValue || node->value >= maxValue) return false;
    
    return isBST(node->left, minValue, node->value) && isBST(node->right, node->value, maxValue);
}

bool isValidBST(const string& tree) {
    int index = 0;
    Node* root = buildTree(tree, index);
    return isBST(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main() {
    string input;
    getline(cin, input);
    
    if (isValidBST(input)) {
        cout << "VERDADEIRO" << endl;
    } else {
        cout << "FALSO" << endl;
    }
    
    return 0;
}
