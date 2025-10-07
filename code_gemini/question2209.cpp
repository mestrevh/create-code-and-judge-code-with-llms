/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, char val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else if (val > root->data) {
        insert(root->right, val);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string generator = "MGTCKQWAEILORUY BDFHJNPSVXZ";
    Node* root = nullptr;

    for (char c : generator) {
        insert(root, c);
    }

    std::string encoded_message;
    std::getline(std::cin, encoded_message);

    encoded_message += '*';
    std::string current_code;

    for (char c : encoded_message) {
        if (c == '*') {
            if (current_code.empty()) {
                continue;
            }

            if (current_code == "@") {
                if (root) {
                    std::cout << root->data;
                }
            } else {
                Node* current_node = root;
                for (char move : current_code) {
                    if (current_node == nullptr) {
                        break; 
                    }
                    if (move == '-') {
                        current_node = current_node->left;
                    } else if (move == '|') {
                        current_node = current_node->right;
                    }
                }
                if (current_node != nullptr) {
                    std::cout << current_node->data;
                }
            }
            current_code = "";
        } else {
            current_code += c;
        }
    }
    std::cout << std::endl;

    return 0;
}
