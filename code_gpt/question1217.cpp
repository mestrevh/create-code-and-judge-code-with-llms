/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

Node* constructTree(string &s) {
    stack<Node*> st;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it != '*') {
            Node* node = new Node(*it);
            if (!st.empty()) {
                node->left = st.top(); st.pop();
                if (!st.empty()) {
                    node->right = st.top(); st.pop();
                }
            }
            st.push(node);
        } else {
            st.push(new Node('*'));
        }
    }
    return st.top();
}

void inorder(Node* root, string &result, int spaces) {
    if (!root) return;
    inorder(root->left, result, spaces + 1);
    for (int i = 0; i < spaces; ++i) result += " ";
    result += root->data;
    result += "\n";
    inorder(root->right, result, spaces + 1);
}

void decodeMessage(Node* root, string &message) {
    if (!root) return;
    if (root->data != '*') {
        message += root->data;
    }
    decodeMessage(root->left, message);
    decodeMessage(root->right, message);
}

int main() {
    string input;
    getline(cin, input);

    Node* root = constructTree(input);
    string decodedMessage;
    decodeMessage(root, decodedMessage);

    string treeStructure;
    inorder(root, treeStructure, 0);

    cout << "Mensagem decodificada: " << decodedMessage << endl;
    cout << "Arvore construida:\n" << treeStructure;

    return 0;
}
