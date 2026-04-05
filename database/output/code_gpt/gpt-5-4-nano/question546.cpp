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

static void skipSpaces(const string& s, size_t& i) {
    while (i < s.size() && isspace((unsigned char)s[i])) i++;
}

static bool parseTree(const string& s, size_t& i, Node*& out) {
    skipSpaces(s, i);
    if (i >= s.size()) return false;

    if (s[i] != '(') return false;
    i++;

    skipSpaces(s, i);
    if (i < s.size() && s[i] == ')') {
        i++;
        out = nullptr;
        return true;
    }

    bool neg = false;
    if (s[i] == '-') { neg = true; i++; }
    if (i >= s.size() || !isdigit((unsigned char)s[i])) return false;

    long long num = 0;
    while (i < s.size() && isdigit((unsigned char)s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    if (neg) num = -num;

    out = new Node();
    out->val = (int)num;

    if (!parseTree(s, i, out->left)) return false;
    if (!parseTree(s, i, out->right)) return false;

    skipSpaces(s, i);
    if (i >= s.size() || s[i] != ')') return false;
    i++;
    return true;
}

static void freeTree(Node* n) {
    if (!n) return;
    freeTree(n->left);
    freeTree(n->right);
    delete n;
}

static bool isBST(Node* n, long long lo, long long hi) {
    if (!n) return true;
    long long v = n->val;
    if (v <= lo || v >= hi) return false;
    return isBST(n->left, lo, v) && isBST(n->right, v, hi);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    while (getline(cin, line)) {
        if (!s.empty()) s.push_back(' ');
        s += line;
    }
    if (s.empty()) return 0;

    size_t i = 0;
    Node* root = nullptr;
    if (!parseTree(s, i, root)) {
        cout << "FALSO";
        return 0;
    }

    cout << (isBST(root, (long long)LLONG_MIN, (long long)LLONG_MAX) ? "VERDADEIRO" : "FALSO");
    freeTree(root);
    return 0;
}