/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* read_tree() {
    char paren;
    
    std::cin >> std::ws;
    if (std::cin.peek() != '(') {
        return nullptr;
    }
    std::cin >> paren; 

    std::cin >> std::ws;
    if (std::cin.peek() == ')') {
        std::cin >> paren;
        return nullptr;
    }

    int val;
    std::cin >> val;
    Node* node = new Node(val);

    node->left = read_tree();
    node->right = read_tree();

    std::cin >> std::ws;
    std::cin >> paren; 

    return node;
}

bool hasPathSum(Node* root, int target_sum) {
    if (root == nullptr) {
        return false;
    }

    int remaining_sum = target_sum - root->value;

    if (root->left == nullptr && root->right == nullptr) {
        return (remaining_sum == 0);
    }

    bool left_path = hasPathSum(root->left, remaining_sum);
    if (left_path) return true;

    bool right_path = hasPathSum(root->right, remaining_sum);
    return right_path;
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
    std::cin.tie(NULL);

    int target_sum;
    while (std::cin >> target_sum) {
        
        Node* root = read_tree();

        bool found = (root != nullptr) && hasPathSum(root, target_sum);

        if (found) {
            std::cout << "sim\n";
        } else {
            std::cout << "nao\n";
        }

        delete_tree(root);
    }

    return 0;
}
