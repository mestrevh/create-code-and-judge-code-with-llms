/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(char c): val(c) {}
};

static void postToTree(const string& s, Node*& root) {
    vector<Node*> st;
    st.reserve(s.size());

    for (char ch : s) {
        if (ch == '*') continue;
        Node* cur = new Node(ch);
        while (!st.empty() && st.back()->val == '*') {
            Node* t = st.back(); st.pop_back();
            if (!cur->left) cur->left = t;
            else if (!cur->right) cur->right = t;
            else {
                cur->right = t;
            }
        }
        st.push_back(cur);
    }

    if (!st.empty()) root = st.front();
    else root = nullptr;
}

static bool isStar(const string& s, size_t i) {
    return s[i] == '*';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    if (!getline(cin, input)) return 0;

    string s;
    s.reserve(input.size());
    for (char ch : input) if (ch != ' ' && ch != '\r' && ch != '\t' && ch != '\n') s.push_back(ch);

    vector<Node*> st;
    st.reserve(s.size());

    for (char ch : s) {
        if (ch == '*') {
            st.push_back(new Node('*'));
        } else {
            Node* cur = new Node(ch);
            Node* a = nullptr;
            Node* b = nullptr;
            if (!st.empty()) { b = st.back(); st.pop_back(); }
            if (!st.empty()) { a = st.back(); st.pop_back(); }
            cur->left = a;
            cur->right = b;
            st.push_back(cur);
        }
    }

    Node* root = nullptr;
    if (!st.empty()) root = st.back();

    vector<pair<Node*, int>> q;
    vector<pair<Node*, int>> nodes;
    if (root) nodes.push_back({root, 0});

    auto cmp = [](const pair<Node*,int>& a, const pair<Node*,int>& b){
        return a.first < b.first;
    };

    function<void(Node*, int)> buildMsg = [&](Node* node, int depth){
        if (!node) return;
        if (node->val != '*') cout << node->val;
        buildMsg(node->left, depth + 1);
        buildMsg(node->right, depth + 1);
    };

    cout << "Mensagem decodificada: ";
    function<void(Node*)> inorder = [&](Node* node){
        if (!node) return;
        inorder(node->left);
        if (node->val != '*') cout << node->val;
        inorder(node->right);
    };
    inorder(root);
    cout << "\n";

    cout << "Arvore construida:\n";
    function<void(Node*, int)> preorderPrint = [&](Node* node, int lvl){
        if (!node) return;
        cout << string(lvl * 1, ' ') << node->val << "\n";
        preorderPrint(node->left, lvl + 1);
        preorderPrint(node->right, lvl + 1);
    };

    function<void(Node*, int)> printWithIndent = [&](Node* node, int lvl){
        if (!node) return;
        for (int i = 0; i < lvl; i++) cout << ' ';
        cout << node->val << "\n";
        printWithIndent(node->left, lvl + 1);
        printWithIndent(node->right, lvl + 1);
    };

    printWithIndent(root, 0);

    return 0;
}