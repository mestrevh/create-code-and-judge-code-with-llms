/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int key;
    string value;
    Node *left, *right;
    Node(int k, string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;
    int size;

    Node* insert(Node* node, int key, string value) {
        if (node == nullptr) {
            size++;
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value;
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* remove(Node* node, int key, string& deletedValue, bool& found) {
        if (node == nullptr) return nullptr;
        if (key < node->key) {
            node->left = remove(node->left, key, deletedValue, found);
        } else if (key > node->key) {
            node->right = remove(node->right, key, deletedValue, found);
        } else {
            found = true;
            deletedValue = node->value;
            size--;
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            string dummy;
            bool dummyFound;
            node->right = remove(node->right, temp->key, dummy, dummyFound);
            size++; // Adjust size because the recursive call above decremented it
        }
        return node;
    }

    void preOrder(Node* node, vector<string>& res) {
        if (node == nullptr) return;
        res.push_back(to_string(node->key) + ":'" + node->value + "'");
        preOrder(node->left, res);
        preOrder(node->right, res);
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) return node;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

public:
    BinaryTree() : root(nullptr), size(0) {}

    void inserir(int key, string value) {
        root = insert(root, key, value);
    }

    string buscar(int key) {
        Node* res = search(root, key);
        if (res == nullptr) return "KeyError";
        return res->value;
    }

    string remover(int key) {
        string deletedValue = "";
        bool found = false;
        root = remove(root, key, deletedValue, found);
        if (!found) return "KeyError";
        return deletedValue;
    }

    int len() {
        return size;
    }

    void printPreOrder() {
        vector<string> res;
        preOrder(root, res);
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i] << (i == res.size() - 1 ? "" : "->");
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BinaryTree tree;
    for (int i = 0; i < 5; ++i) {
        int k;
        string v;
        if (!(cin >> k)) break;
        cin.ignore();
        getline(cin, v);
        tree.inserir(k, v);
    }

    char cmd;
    while (cin >> cmd) {
        if (cmd == 'P') {
            tree.printPreOrder();
        } else if (cmd == 'L') {
            cout << tree.len() << endl;
        } else if (cmd == 'B') {
            int k;
            cin >> k;
            string res = tree.buscar(k);
            if (res != "KeyError") cout << res << endl;
        } else if (cmd == 'R') {
            int k;
            cin >> k;
            string res = tree.remover(k);
            if (res != "KeyError") cout << res << endl;
        }
    }

    return 0;
}