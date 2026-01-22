/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Node {
    int value;
    Node *left;
    Node *right;
    int size;

    Node(int val) : value(val), left(nullptr), right(nullptr), size(1) {}
};

class BST {
private:
    Node* root;

    int getSize(Node* node) {
        return node ? node->size : 0;
    }

    void updateSize(Node* node) {
        if (node) {
            node->size = 1 + getSize(node->left) + getSize(node->right);
        }
    }

    Node* insert_recursive(Node* node, int val, int level, int& result_level) {
        if (!node) {
            result_level = level;
            return new Node(val);
        }

        if (val == node->value) {
            result_level = level;
            return node;
        }

        if (val < node->value) {
            node->left = insert_recursive(node->left, val, level + 1, result_level);
        } else {
            node->right = insert_recursive(node->right, val, level + 1, result_level);
        }

        updateSize(node);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* remove_recursive(Node* node, int val, int level, int& result_level) {
        if (!node) {
            result_level = -1;
            return nullptr;
        }

        if (val < node->value) {
            node->left = remove_recursive(node->left, val, level + 1, result_level);
        } else if (val > node->value) {
            node->right = remove_recursive(node->right, val, level + 1, result_level);
        } else {
            result_level = level;

            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* successor = findMin(node->right);
            node->value = successor->value;
            int dummy_level;
            node->right = remove_recursive(node->right, successor->value, level + 1, dummy_level);
        }
        
        updateSize(node);
        return node;
    }

    int countGreater_recursive(Node* node, int val) {
        if (!node) {
            return 0;
        }

        if (val < node->value) {
            return 1 + getSize(node->right) + countGreater_recursive(node->left, val);
        } else {
            return countGreater_recursive(node->right, val);
        }
    }

    int findKth_recursive(Node* node, int k) {
        int left_size = getSize(node->left);
        
        if (k == left_size + 1) {
            return node->value;
        }
        
        if (k <= left_size) {
            return findKth_recursive(node->left, k);
        } else {
            return findKth_recursive(node->right, k - left_size - 1);
        }
    }

    void destroy_tree(Node* node) {
        if (node) {
            destroy_tree(node->left);
            destroy_tree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        destroy_tree(root);
    }

    int insert(int val) {
        int result_level;
        root = insert_recursive(root, val, 0, result_level);
        return result_level;
    }

    int remove(int val) {
        int result_level;
        root = remove_recursive(root, val, 0, result_level);
        return result_level;
    }

    int countGreater(int val) {
        return countGreater_recursive(root, val);
    }
    
    int findKth(int k) {
        if (k <= 0 || k > getSize(root)) {
            return -1; 
        }
        return findKth_recursive(root, k);
    }
};

void solve() {
    int N;
    std::cin >> N;
    BST tree;
    for (int i = 0; i < N; ++i) {
        int C, X;
        std::cin >> C >> X;
        if (C == 1) {
            std::cout << tree.insert(X) << "\n";
        } else if (C == 2) {
            std::cout << tree.remove(X) << "\n";
        } else if (C == 3) {
            std::cout << tree.countGreater(X) << "\n";
        } else if (C == 4) {
            std::cout << tree.findKth(X) << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
        if (T > 0) {
            std::cout << "\n";
        }
    }

    return 0;
}
