/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>

using KeyType = unsigned int;

const KeyType MOD = 11881376;

KeyType hashcode(const std::string& s) {
    KeyType h = 0;
    for (char c : s) {
        h = (static_cast<unsigned long long>(26) * h + (c - 'a')) % MOD;
    }
    return h;
}

struct Data {
    std::string word;
    std::vector<int> lines;
};

struct Node {
    KeyType key;
    Data value;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 1;
};

class AVLMap {
private:
    Node* root = nullptr;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    void updateHeight(Node* n) {
        if (n) {
            n->height = 1 + std::max(height(n->left), height(n->right));
        }
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

    int compare(KeyType k1, const std::string& w1, KeyType k2, const std::string& w2) {
        if (k1 < k2) return -1;
        if (k1 > k2) return 1;
        if (w1 < w2) return -1;
        if (w1 > w2) return 1;
        return 0;
    }

    Node* insert(Node* node, KeyType key, const std::string& word, int line) {
        if (!node) {
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value.word = word;
            newNode->value.lines.push_back(line);
            return newNode;
        }

        int cmp = compare(key, word, node->key, node->value.word);

        if (cmp < 0) {
            node->left = insert(node->left, key, word, line);
        } else if (cmp > 0) {
            node->right = insert(node->right, key, word, line);
        } else {
            if (node->value.lines.empty() || node->value.lines.back() != line) {
                node->value.lines.push_back(line);
            }
            return node;
        }

        updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && compare(key, word, node->left->key, node->left->value.word) < 0) {
            return rightRotate(node);
        }

        if (balance < -1 && compare(key, word, node->right->key, node->right->value.word) > 0) {
            return leftRotate(node);
        }

        if (balance > 1 && compare(key, word, node->left->key, node->left->value.word) > 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && compare(key, word, node->right->key, node->right->value.word) < 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    
    std::pair<Data*, int> find(Node* node, KeyType key, const std::string& word, int depth) {
        if (!node) {
            return {nullptr, 0};
        }

        int cmp = compare(key, word, node->key, node->value.word);

        if (cmp < 0) {
            return find(node->left, key, word, depth + 1);
        } else if (cmp > 0) {
            return find(node->right, key, word, depth + 1);
        } else {
            return {&(node->value), depth};
        }
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    ~AVLMap() {
        destroy(root);
    }

    void insert(const std::string& word, int line) {
        if (word.empty()) return;
        KeyType key = hashcode(word);
        root = insert(root, key, word, line);
    }

    std::pair<Data*, int> find(const std::string& word) {
        if (word.empty()) return {nullptr, 0};
        KeyType key = hashcode(word);
        return find(root, key, word, 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    AVLMap avlMap;
    std::string line, word;

    std::getline(std::cin, line);

    int line_number = 1;
    while (std::getline(std::cin, line) && line != "$CONSULTAS") {
        std::stringstream ss(line);
        while (ss >> word) {
            avlMap.insert(word, line_number);
        }
        line_number++;
    }

    while (std::cin >> word) {
        std::pair<Data*, int> result = avlMap.find(word);
        std::cout << word << " " << result.second;
        if (result.first) {
            for (int l : result.first->lines) {
                std::cout << " " << l;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
