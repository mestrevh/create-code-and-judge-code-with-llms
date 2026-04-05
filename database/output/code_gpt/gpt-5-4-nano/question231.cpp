/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* left = nullptr;
    Node* right = nullptr;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long target;
    while (true) {
        if (!(cin >> target)) return 0;
        if (target == -1000) break;

        auto skipSpaces = [&]() {
            while (true) {
                int c = cin.peek();
                if (c == EOF) return;
                if (isspace(c)) cin.get();
                else break;
            }
        };

        function<Node*()> parseTree = [&]() -> Node* {
            skipSpaces();
            int c = cin.peek();
            if (c == EOF) return nullptr;
            if (c != '(') return nullptr;
            cin.get(); 

            skipSpaces();
            c = cin.peek();
            if (c == ')') {
                cin.get();
                return nullptr;
            }

            long long v;
            cin >> v;
            Node* n = new Node();
            n->val = v;

            n->left = parseTree();
            n->right = parseTree();

            skipSpaces();
            cin.get(); 
            return n;
        };

        function<bool(Node*, long long)> dfs = [&](Node* node, long long sum) -> bool {
            if (!node) return false;
            sum += node->val;
            bool isLeaf = (node->left == nullptr && node->right == nullptr);
            if (isLeaf) return sum == target;
            return dfs(node->left, sum) || dfs(node->right, sum);
        };

        Node* root = parseTree();
        bool ok = dfs(root, 0);

        cout << (ok ? "sim" : "nao") << "\n";

        function<void(Node*)> cleanup = [&](Node* node) {
            if (!node) return;
            cleanup(node->left);
            cleanup(node->right);
            delete node;
        };
        cleanup(root);
    }
    return 0;
}