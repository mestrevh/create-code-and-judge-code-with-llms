/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

unsigned int calculateHash(const string& w) {
    unsigned int h = 0;
    for (char c : w) {
        if (c >= 'a' && c <= 'z')
            h = (26 * h + (unsigned int)(c - 'a')) % 11881376;
    }
    return h;
}

struct Node {
    unsigned int h;
    string w;
    vector<int> lines;
    int height;
    Node *left, *right;

    Node(unsigned int hash, const string& word, int line) : 
        h(hash), w(word), height(1), left(nullptr), right(nullptr) {
        lines.push_back(line);
    }
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int cmp_keys(unsigned int h1, const string& w1, unsigned int h2, const string& w2) {
    if (h1 < h2) return -1;
    if (h1 > h2) return 1;
    if (w1 < w2) return -1;
    if (w1 > w2) return 1;
    return 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insert(Node* node, unsigned int h, const string& w, int line) {
    if (!node) return new Node(h, w, line);

    int cmp = cmp_keys(h, w, node->h, node->w);

    if (cmp < 0) {
        node->left = insert(node->left, h, w, line);
    } else if (cmp > 0) {
        node->right = insert(node->right, h, w, line);
    } else {
        if (node->lines.back() != line) {
            node->lines.push_back(line);
        }
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getHeight(node->left) - getHeight(node->right);

    if (balance > 1) {
        if (cmp_keys(h, w, node->left->h, node->left->w) < 0)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        if (cmp_keys(h, w, node->right->h, node->right->w) > 0)
            return rotateLeft(node);
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

Node* find(Node* node, unsigned int h, const string& w, int& depth) {
    int currentDepth = 1;
    Node* curr = node;
    while (curr) {
        int cmp = cmp_keys(h, w, curr->h, curr->w);
        if (cmp == 0) {
            depth = currentDepth;
            return curr;
        }
        if (cmp < 0) curr = curr->left;
        else curr = curr->right;
        currentDepth++;
    }
    depth = 0;
    return nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;
    // Some systems may have leading/trailing whitespace
    while (line != "$TEXTO") {
        if (!getline(cin, line)) return 0;
    }

    Node* root = nullptr;
    int lineCount = 0;
    while (getline(cin, line) && line != "$CONSULTAS") {
        lineCount++;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            unsigned int h = calculateHash(word);
            root = insert(root, h, word, lineCount);
        }
    }

    while (getline(cin, line)) {
        if (line.empty()) continue;
        // The query string itself might have spaces if read with getline, 
        // but based on problem Qj is a single word.
        stringstream ss(line);
        string queryWord;
        if (!(ss >> queryWord)) continue;
        
        unsigned int h = calculateHash(queryWord);
        int depth = 0;
        Node* res = find(root, h, queryWord, depth);
        cout << queryWord << " " << depth;
        if (res) {
            for (int l : res->lines) {
                cout << " " << l;
            }
        }
        cout << "\n";
    }

    return 0;
}

