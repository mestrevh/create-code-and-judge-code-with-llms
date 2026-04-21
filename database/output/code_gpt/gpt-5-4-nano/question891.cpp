/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

struct Frame {
    Node* parent = nullptr;
    bool isLeft = false;
    int state = 0; // 0 expecting val or ')', 1 expecting left subtree, 2 expecting right subtree
    Node* created = nullptr;
    int val = 0;
};

class Parser {
    string s;
    size_t i = 0;
public:
    Parser(string str) : s(std::move(str)) {}

    Node* parse() {
        if (s.empty()) return nullptr;
        if (peek() == '(') {
            advance(); // '('
            if (peek() == ')') {
                advance(); // ')'
                return nullptr;
            }
            int v = parseInt();
            if (peek() != ':') return nullptr;
            advance(); // ':'
            Node* node = new Node();
            node->val = v;

            node->left = parseSubtree();
            if (peek() == ':') advance();
            node->right = parseSubtree();

            if (peek() == ')') advance();
            return node;
        }
        return nullptr;
    }

private:
    char peek() const { return i < s.size() ? s[i] : '\0'; }
    void advance() { if (i < s.size()) i++; }

    int parseInt() {
        bool neg = false;
        if (peek() == '-') { neg = true; advance(); }
        long long x = 0;
        while (i < s.size() && isdigit((unsigned char)s[i])) {
            x = x * 10 + (s[i] - '0');
            i++;
        }
        return neg ? -(int)x : (int)x;
    }

    Node* parseSubtree() {
        if (peek() == '(') {
            advance(); // '('
            if (peek() == ')') {
                advance(); // ')'
                return nullptr;
            }
            int v = parseInt();
            if (peek() == ':') advance();
            Node* node = new Node();
            node->val = v;
            node->left = parseSubtree();
            if (peek() == ':') advance();
            node->right = parseSubtree();
            if (peek() == ')') advance();
            return node;
        }
        return nullptr;
    }
};

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

pair<bool, pair<int,int>> checkBST(Node* root) {
    // returns {isBST, {minVal, maxVal}} using long long bounds but store int
    if (!root) return {true, {INT_MAX, INT_MIN}};
    auto L = checkBST(root->left);
    if (!L.first) return {false, {0,0}};
    auto R = checkBST(root->right);
    if (!R.first) return {false, {0,0}};
    if (root->left && L.second.second >= root->val) return {false, {0,0}};
    if (root->right && R.second.first <= root->val) return {false, {0,0}};
    int mn = min(root->val, L.second.first);
    int mx = max(root->val, R.second.second);
    return {true, {mn, mx}};
}

int getMinBSTValue(Node* root) {
    Node* cur = root;
    while (cur && cur->left) cur = cur->left;
    return cur->val;
}

void removeAllOccurrences(Node*& root, int x) {
    // BST is assumed, but we maintain our own BST; removal with duplicates not allowed.
    function<Node*(Node*)> rec = [&](Node* r) -> Node* {
        if (!r) return r;
        if (x < r->val) {
            r->left = rec(r->left);
            return r;
        } else if (x > r->val) {
            r->right = rec(r->right);
            return r;
        } else {
            if (!r->left) {
                Node* t = r->right;
                delete r;
                return t;
            }
            if (!r->right) {
                Node* t = r->left;
                delete r;
                return t;
            }
            Node* succParent = r;
            Node* succ = r->right;
            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }
            r->val = succ->val;
            if (succParent == r) succParent->right = succ->right;
            else succParent->left = succ->right;
            delete succ;
            return r;
        }
    };
    root = rec(root);
}

bool insertBST(Node*& root, int x) {
    if (!root) {
        root = new Node{ x,nullptr,nullptr };
        return true;
    }
    Node* cur = root;
    Node* parent = nullptr;
    bool left = false;
    while (cur) {
        parent = cur;
        if (x == cur->val) return false;
        if (x < cur->val) { cur = cur->left; left = true; }
        else { cur = cur->right; left = false; }
    }
    Node* n = new Node{ x,nullptr,nullptr };
    if (left) parent->left = n;
    else parent->right = n;
    return true;
}

void postorderCollect(Node* root, vector<int>& out) {
    if (!root) return;
    postorderCollect(root->left, out);
    postorderCollect(root->right, out);
    out.push_back(root->val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    Node* gabi = nullptr;

    while (true) {
        if (!std::getline(cin, line)) break;
        if (line.empty()) continue;

        Parser p(line);
        Node* T = p.parse();
        if (!T) continue;

        auto bstCheck = checkBST(T);
        if (bstCheck.first) {
            int mn = getMinBSTValue(T);
            insertBST(gabi, mn);
        } else {
            removeAllOccurrences(gabi, T->val);
        }

        freeTree(T);
    }

    vector<int> res;
    postorderCollect(gabi, res);
    for (int x : res) cout << x << "\n";
    freeTree(gabi);
    return 0;
}