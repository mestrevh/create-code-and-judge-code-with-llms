/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    string value;
    Node *left, *right;
    Node(int k, const string& v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;

    static Node* insertNode(Node* cur, int key, const string& val) {
        if (!cur) return new Node(key, val);
        if (key < cur->key) cur->left = insertNode(cur->left, key, val);
        else if (key > cur->key) cur->right = insertNode(cur->right, key, val);
        else cur->value = val;
        return cur;
    }

    static size_t countNodes(Node* cur) {
        if (!cur) return 0;
        return 1 + countNodes(cur->left) + countNodes(cur->right);
    }

    static void preorderPrint(Node* cur, vector<string>& out) {
        if (!cur) return;
        string s = to_string(cur->key) + ":'" + cur->value + "'";
        out.push_back(s);
        preorderPrint(cur->left, out);
        preorderPrint(cur->right, out);
    }

    static string findValue(Node* cur, int key) {
        if (!cur) throw out_of_range("KeyError");
        if (key == cur->key) return cur->value;
        if (key < cur->key) return findValue(cur->left, key);
        return findValue(cur->right, key);
    }

    static Node* minNode(Node* cur) {
        Node* p = cur;
        while (p && p->left) p = p->left;
        return p;
    }

    static Node* removeNode(Node* cur, int key, string& removedValue) {
        if (!cur) throw out_of_range("KeyError");
        if (key < cur->key) {
            cur->left = removeNode(cur->left, key, removedValue);
            return cur;
        }
        if (key > cur->key) {
            cur->right = removeNode(cur->right, key, removedValue);
            return cur;
        }

        removedValue = cur->value;

        if (!cur->left && !cur->right) {
            delete cur;
            return nullptr;
        }
        if (!cur->left) {
            Node* r = cur->right;
            delete cur;
            return r;
        }
        if (!cur->right) {
            Node* l = cur->left;
            delete cur;
            return l;
        }

        Node* succ = minNode(cur->right);
        cur->key = succ->key;
        cur->value = succ->value;
        string dummy;
        cur->right = removeNode(cur->right, succ->key, dummy);
        return cur;
    }

    static void destroy(Node* cur) {
        if (!cur) return;
        destroy(cur->left);
        destroy(cur->right);
        delete cur;
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { destroy(root); }

    void insertItem(int key, const string& val) {
        root = insertNode(root, key, val);
    }

    size_t size() const {
        return countNodes(root);
    }

    void printPreorder(ostream& os) const {
        vector<string> parts;
        preorderPrint(root, parts);
        for (size_t i = 0; i < parts.size(); i++) {
            if (i) os << "->";
            os << parts[i];
        }
        os << "\n";
    }

    string buscar(int key) const {
        return findValue(root, key);
    }

    string remover(int key) {
        string removed;
        root = removeNode(root, key, removed);
        return removed;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BinaryTree tree;

    vector<int> keys = {15, 66, 1, 50, 11};
    vector<string> vals = {"quinze", "sessenta e seis", "um", "cinquenta", "onze"};
    for (int i = 0; i < 5; i++) {
        int k;
        string v;
        if (!(cin >> k)) return 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, v);
        tree.insertItem(k, v);
    }

    char cmd;
    while (cin >> cmd) {
        if (cmd == 'P') {
            tree.printPreorder(cout);
        } else if (cmd == 'L') {
            cout << tree.size() << "\n";
        } else if (cmd == 'B') {
            int key;
            cin >> key;
            string res = tree.buscar(key);
            cout << res << "\n";
        } else if (cmd == 'R') {
            int key;
            cin >> key;
            string res = tree.remover(key);
            cout << res << "\n";
        } else {
            break;
        }
    }

    return 0;
}