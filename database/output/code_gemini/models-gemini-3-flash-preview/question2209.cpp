/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    char val;
    Node *left, *right;
    Node(char v) : val(v), left(nullptr), right(nullptr) {}
};

// Standard Binary Search Tree insertion
Node* insert(Node* root, char c) {
    if (!root) return new Node(c);
    // In C++, char comparison uses ASCII values. 
    // Space (' ') has ASCII 32, while 'A'-'Z' have 65-90.
    if (c < root->val) {
        root->left = insert(root->left, c);
    } else if (c > root->val) {
        root->right = insert(root->right, c);
    }
    return root;
}

// Function to decode a single Madd Code token
void processToken(Node* root, const string& token) {
    if (token.empty()) return;
    
    // The '@' character specifically represents the root node
    if (token == "@") {
        cout << root->val;
        return;
    }
    
    Node* curr = root;
    for (char move : token) {
        if (move == '-') {
            if (curr->left) curr = curr->left;
        } else if (move == '|') {
            if (curr->right) curr = curr->right;
        }
    }
    
    if (curr) {
        cout << curr->val;
    }
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The String Geradora provided in the problem description
    string gen = "MGTCKQWAEILORUY BDFHJNPSVXZ";
    
    // Build the Madd Code BST
    Node* root = nullptr;
    for (char c : gen) {
        root = insert(root, c);
    }

    // Read and decode the input messages
    string input;
    while (cin >> input) {
        string token = "";
        for (char c : input) {
            if (c == '*') {
                processToken(root, token);
                token = "";
            } else {
                token += c;
            }
        }
        // Process any remaining token not followed by '*'
        if (!token.empty()) {
            processToken(root, token);
        }
        cout << "\n";
    }

    return 0;
}