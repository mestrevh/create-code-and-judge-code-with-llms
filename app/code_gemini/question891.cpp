/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* parseTree(const std::string& s, int& pos) {
    pos++; 
    if (pos >= s.length() || s[pos] == ')') {
        pos++;
        return nullptr;
    }

    int val = 0;
    while (pos < s.length() && std::isdigit(s[pos])) {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    
    Node* root = new Node(val);
    pos++; 

    root->left = parseTree(s, pos);
    root->right = parseTree(s, pos);

    pos++; 

    return root;
}

bool isBSTUtil(Node* node, long long min_val, long long max_val) {
    if (!node) {
        return true;
    }
    if (node->val <= min_val || node->val >= max_val) {
        return false;
    }
    return isBSTUtil(node->left, min_val, node->val) &&
           isBSTUtil(node->right, node->val, max_val);
}

bool isBST(Node* root) {
    return isBSTUtil(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
}

int findMin(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root->val;
}

void deleteTree(Node* node) {
    if (!node) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* findMinNode(Node* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

Node* remove(Node* root, int val) {
    if (!root) {
        return root;
    }

    if (val < root->val) {
        root->left = remove(root->left, val);
    } else if (val > root->val) {
        root->right = remove(root->right, val);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMinNode(root->right);
        root->val = temp->val;
        root->right = remove(root->right, temp->val);
    }
    return root;
}

void postOrder(Node* root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->val << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* gabi_root = nullptr;
    std::string line;

    while (std::getline(std::cin, line)) {
        size_t first = line.find_first_not_of(" \t\n\v\f\r");
        if (std::string::npos == first) {
            continue;
        }
        size_t last = line.find_last_not_of(" \t\n\v\f\r");
        line = line.substr(first, (last - first + 1));
        
        if (line.empty()) {
            continue;
        }
        
        int pos = 0;
        Node* current_tree = parseTree(line, pos);

        if (current_tree != nullptr) {
            if (isBST(current_tree)) {
                int min_val = findMin(current_tree);
                gabi_root = insert(gabi_root, min_val);
            } else {
                int root_val = current_tree->val;
                gabi_root = remove(gabi_root, root_val);
            }
            deleteTree(current_tree);
        }
    }

    postOrder(gabi_root);
    deleteTree(gabi_root);

    return 0;
}
