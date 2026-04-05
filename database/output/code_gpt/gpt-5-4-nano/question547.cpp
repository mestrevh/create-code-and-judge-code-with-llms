/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

static string s;
static size_t iPos;

Node* parseNode() {
    if (iPos >= s.size() || s[iPos] != '(') return nullptr;
    ++iPos;
    if (iPos >= s.size()) return nullptr;
    if (s[iPos] == ')') {
        ++iPos;
        return nullptr;
    }
    int sign = 1;
    if (s[iPos] == '-') {
        sign = -1;
        ++iPos;
    }
    long long v = 0;
    while (iPos < s.size() && isdigit((unsigned char)s[iPos])) {
        v = v * 10 + (s[iPos] - '0');
        ++iPos;
    }
    Node* node = new Node((int)(v * sign));
    node->left = parseNode();
    node->right = parseNode();
    if (iPos < s.size() && s[iPos] == ')') ++iPos;
    return node;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string treeStr;
    if (!getline(cin, treeStr)) return 0;

    long long n;
    cin >> n;

    s = treeStr;
    iPos = 0;
    Node* root = nullptr;

    if (!s.empty() && s[0] == '(') root = parseNode();

    bool found = false;
    int depthAns = -1;

    queue<pair<Node*, int>> q;
    if (root) q.push({root, 1});
    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();
        if (node->val == n) {
            found = true;
            depthAns = depth;
            break;
        }
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }

    if (found) cout << "ESTA NA ARVORE\n";
    else cout << "NAO ESTA NA ARVORE\n";
    cout << depthAns << "\n";

    freeTree(root);
    return 0;
}