/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stdexcept>

class Node {
public:
    int key;
    std::string value;
    Node* left;
    Node* right;

    Node(int k, std::string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insert(Node*& node, int key, std::string value) {
        if (!node) {
            node = new Node(key, value);
        } else if (key < node->key) {
            insert(node->left, key, value);
        } else if (key > node->key) {
            insert(node->right, key, value);
        }
    }

    void preorder(Node* node, std::string& result) {
        if (node) {
            result += std::to_string(node->key) + ":'" + node->value + "'->";
            preorder(node->left, result);
            preorder(node->right, result);
        }
    }

    Node* search(Node* node, int key) {
        if (!node) throw std::runtime_error("KeyError");
        if (key == node->key) return node;
        return key < node->key ? search(node->left, key) : search(node->right, key);
    }

    Node* remove(Node* node, int key, std::string& value) {
        if (!node) throw std::runtime_error("KeyError");
        if (key < node->key) {
            node->left = remove(node->left, key, value);
        } else if (key > node->key) {
            node->right = remove(node->right, key, value);
        } else {
            value = node->value;
            if (!node->left) {
                Node* rightNode = node->right;
                delete node;
                return rightNode;
            } else if (!node->right) {
                Node* leftNode = node->left;
                delete node;
                return leftNode;
            } else {
                Node* minNode = node->right;
                while (minNode->left) minNode = minNode->left;
                node->key = minNode->key;
                node->value = minNode->value;
                node->right = remove(node->right, minNode->key, value);
            }
        }
        return node;
    }

    int count(Node* node) {
        return node ? 1 + count(node->left) + count(node->right) : 0;
    }

public:
    BinaryTree() : root(nullptr) {}

    void inserir(int key, std::string value) {
        insert(root, key, value);
    }

    std::string str() {
        std::string result;
        preorder(root, result);
        if (!result.empty()) result.erase(result.end() - 2, result.end());
        return result;
    }

    int len() {
        return count(root);
    }

    std::string buscar(int key) {
        return search(root, key)->value;
    }

    std::string remover(int key) {
        std::string value;
        root = remove(root, key, value);
        return value;
    }
};

int main() {
    BinaryTree tree;
    tree.inserir(15, "quinze");
    tree.inserir(66, "sessenta e seis");
    tree.inserir(1, "um");
    tree.inserir(50, "cinquenta");
    tree.inserir(11, "onze");

    std::cout << tree.str() << std::endl;
    std::cout << tree.len() << std::endl;

    std::cout << tree.remover(66) << std::endl;
    std::cout << tree.buscar(50) << std::endl;
    std::cout << tree.str() << std::endl;

    return 0;
}
