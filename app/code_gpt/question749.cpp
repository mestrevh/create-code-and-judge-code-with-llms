/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <unordered_map>

using namespace std;

class AVLNode {
public:
    string key;
    vector<int> lines;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(const string& k, int line) : key(k), height(1), left(nullptr), right(nullptr) {
        lines.push_back(line);
    }
};

class AVLMap {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(AVLNode* node) {
        return height(node->left) - height(node->right);
    }

    void fixHeight(AVLNode* node) {
        int h_left = height(node->left);
        int h_right = height(node->right);
        node->height = max(h_left, h_right) + 1;
    }

    AVLNode* rotateRight(AVLNode* node) {
        AVLNode* left = node->left;
        node->left = left->right;
        left->right = node;
        fixHeight(node);
        fixHeight(left);
        return left;
    }

    AVLNode* rotateLeft(AVLNode* node) {
        AVLNode* right = node->right;
        node->right = right->left;
        right->left = node;
        fixHeight(node);
        fixHeight(right);
        return right;
    }

    AVLNode* balance(AVLNode* node) {
        fixHeight(node);
        if (balanceFactor(node) == 2) {
            if (balanceFactor(node->right) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor(node) == -2) {
            if (balanceFactor(node->left) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* insert(AVLNode* node, const string& key, int line) {
        if (!node) return new AVLNode(key, line);
        if (key < node->key) {
            node->left = insert(node->left, key, line);
        } else if (key > node->key) {
            node->right = insert(node->right, key, line);
        } else {
            if (find(node->lines.begin(), node->lines.end(), line) == node->lines.end())
                node->lines.push_back(line);
        }
        return balance(node);
    }

    AVLNode* find(AVLNode* node, const string& key) {
        if (!node) return nullptr;
        if (node->key == key) return node;
        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }

public:
    AVLMap() : root(nullptr) {}

    void insert(const string& key, int line) {
        root = insert(root, key, line);
    }

    AVLNode* find(const string& key) {
        return find(root, key);
    }

    int getDepth(AVLNode* node) {
        if (!node) return 0;
        return (getDepth(node->left) || getDepth(node->right)) + 1;
    }

    AVLNode* getRoot() { return root; }
};

unsigned int hashcode(const string& word) {
    unsigned int hash = 0;
    for (char c : word) {
        hash = (hash * 26 + (c - 'a')) % 11881376;
    }
    return hash;
}

int main() {
    string line, text, consulta;
    AVLMap avl;

    getline(cin, line); // Ignore $TEXTO
    int lineNum = 1;

    while (getline(cin, line) && line != "$CONSULTAS") {
        istringstream iss(line);
        string word;
        istringstream iss2(line);
        while (iss2 >> word) {
            avl.insert(word, lineNum);
        }
        lineNum++;
    }

    while (getline(cin, consulta)) {
        AVLNode* result = avl.find(consulta);
        if (result) {
            cout << consulta << " " << avl.getDepth(result) << " ";
            for (int i = 0; i < result->lines.size(); i++) {
                cout << result->lines[i];
                if (i < result->lines.size() - 1) cout << " ";
            }
            cout << endl;
        } else {
            cout << consulta << " 0" << endl;
        }
    }
    return 0;
}
