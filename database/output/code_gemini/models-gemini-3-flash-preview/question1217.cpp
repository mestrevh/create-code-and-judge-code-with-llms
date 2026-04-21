/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    char value;
    Node *left, *right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

// In-order traversal to decode the message, ignoring '*' characters
void inOrder(Node* n) {
    if (!n) return;
    inOrder(n->left);
    if (n->value != '*') cout << n->value;
    inOrder(n->right);
}

// Pre-order traversal to print the tree with indentation based on level
void printTree(Node* n, int level) {
    if (!n) return;
    for (int i = 0; i < level; ++i) cout << ' ';
    cout << n->value << '\n';
    printTree(n->left, level + 1);
    printTree(n->right, level + 1);
}

// Function to safely delete the tree and free memory
void deleteTree(Node* n) {
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Read each post-order string from input
    while (getline(cin, s)) {
        if (s.empty()) continue;
        
        stack<Node*> st;
        for (char c : s) {
            Node* n = new Node(c);
            // Based on problem logic, non-'*' nodes are internal nodes with two children
            if (c != '*') {
                // Pop the right child first, then the left child (standard post-order logic)
                if (!st.empty()) {
                    n->right = st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    n->left = st.top();
                    st.pop();
                }
            }
            // '*' nodes are leaves (children) and have no children of their own
            st.push(n);
        }

        if (!st.empty()) {
            Node* root = st.top();
            
            // Output 1: Decoded message using in-order traversal
            cout << "Mensagem decodificada: ";
            inOrder(root);
            cout << '\n';
            
            // Output 2: Tree structure with specified level-based indentation
            cout << "Arvore construida:\n";
            printTree(root, 0);
            
            // Clean up memory
            deleteTree(root);
        }
    }

    return 0;
}