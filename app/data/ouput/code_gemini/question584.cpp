/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using KeyType = long long;

struct Node {
    KeyType key;
    int height;
    Node *left;
    Node *right;

    Node(KeyType k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    void updateHeight(Node* n) {
        if (n) {
            n->height = 1 + std::max(height(n->left), height(n->right));
        }
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* insert(Node* node, KeyType key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* node, KeyType key) {
        if (!node) {
            return node;
        }

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        } else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        if (!node) {
            return node;
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* findNode(Node* node, KeyType key) {
        if (!node || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return findNode(node->left, key);
        } else {
            return findNode(node->right, key);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void add(KeyType key) {
        root = insert(root, key);
    }
    
    int del(KeyType key) {
        Node* node_to_delete = findNode(root, key);
        if (!node_to_delete) {
            return 0;
        }
        int h = node_to_delete->height;
        root = deleteNode(root, key);
        return h;
    }
    
    int qry(KeyType key) {
        Node* node = findNode(root, key);
        return node ? node->height : 0;
    }

    std::pair<KeyType, bool> find_smallest_ge(KeyType l) {
        Node* current = root;
        KeyType best_so_far = -1;
        bool found = false;
        while(current != nullptr){
            if(current->key >= l){
                best_so_far = current->key;
                found = true;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return {best_so_far, found};
    }

    std::pair<KeyType, bool> find_largest_le(KeyType r) {
        Node* current = root;
        KeyType best_so_far = -1;
        bool found = false;
        while(current != nullptr){
            if(current->key <= r){
                best_so_far = current->key;
                found = true;
                current = current->right;
            } else {
                current = current->left;
            }
        }
        return {best_so_far, found};
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, M, seedX, A, C;
    std::cin >> N >> M >> seedX >> A >> C;

    AVLTree bst;

    long long currentX = seedX;
    if (M != 0) {
        for (long long i = 0; i < N; ++i) {
            bst.add(currentX);
            currentX = (A * currentX + C);
            currentX = (currentX % M + M) % M;
        }
    }

    std::string command;
    int op_count = 0;
    while (std::cin >> command) {
        std::cout << op_count++ << " ";
        if (command == "ADD") {
            KeyType k;
            std::cin >> k;
            bst.add(k);
            std::cout << bst.qry(k) << "\n";
        } else if (command == "DEL") {
            KeyType k;
            std::cin >> k;
            std::cout << bst.del(k) << "\n";
        } else if (command == "QRY") {
            KeyType k;
            std::cin >> k;
            std::cout << bst.qry(k) << "\n";
        } else if (command == "INT") {
            KeyType l, r;
            std::cin >> l >> r;
            auto min_res = bst.find_smallest_ge(l);
            if (min_res.second && min_res.first <= r) {
                auto max_res = bst.find_largest_le(r);
                std::cout << min_res.first << " " << max_res.first << "\n";
            } else {
                std::cout << "\n";
            }
        }
    }

    return 0;
}
