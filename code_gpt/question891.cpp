/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* parseTree(std::string& s) {
    if (s.empty() || s == "()") return nullptr;
    int pos = s.find(':');
    int value = std::stoi(s.substr(1, pos - 1));
    Node* root = new Node(value);
    int start = pos + 1, count = 1;
    for (int i = start; i < s.size(); ++i) {
        if (s[i] == '(') count++;
        else if (s[i] == ')') count--;
        if (count == 0) {
            root->left = parseTree(s.substr(start, i - start + 1));
            root->right = parseTree(s.substr(i + 1));
            break;
        }
    }
    return root;
}

bool isBST(Node* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (!root) return true;
    if (root->value <= minVal || root->value >= maxVal) return false;
    return isBST(root->left, minVal, root->value) && isBST(root->right, root->value, maxVal);
}

void postOrder(Node* root, std::vector<int>& result) {
    if (!root) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->value);
}

void processTree(Node* root, std::set<int>& gabisTree) {
    if (!root) return;
    if (isBST(root)) {
        gabisTree.insert(root->value);
    } else {
        gabisTree.erase(root->value);
    }
    processTree(root->left, gabisTree);
    processTree(root->right, gabisTree);
}

int main() {
    std::set<int> gabisTree;
    std::string line;
    while (std::getline(std::cin, line)) {
        Node* root = parseTree(line);
        processTree(root, gabisTree);
    }

    std::vector<int> result(gabisTree.begin(), gabisTree.end());
    std::sort(result.begin(), result.end());
    for (int v : result) {
        std::cout << v << std::endl;
    }
    
    return 0;
}
