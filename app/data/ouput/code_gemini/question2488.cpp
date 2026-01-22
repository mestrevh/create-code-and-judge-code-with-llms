/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <limits>

struct Node {
    int key;
    std::string value;
    Node* left;
    Node* right;

    Node(int k, const std::string& v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    size_t count;

    Node* inserir_helper(Node* node, int key, const std::string& value) {
        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = inserir_helper(node->left, key, value);
        } else if (key > node->key) {
            node->right = inserir_helper(node->right, key, value);
        } else {
            node->value = value;
        }
        return node;
    }

    Node* buscar_helper(Node* node, int key) const {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return buscar_helper(node->left, key);
        }
        return buscar_helper(node->right, key);
    }

    Node* find_min(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* remover_helper(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = remover_helper(node->left, key);
        } else if (key > node->key) {
            node->right = remover_helper(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = find_min(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = remover_helper(node->right, temp->key);
        }
        return node;
    }

    void print_pre_order_helper(Node* node, bool& is_first) const {
        if (node == nullptr) {
            return;
        }
        if (!is_first) {
            std::cout << "->";
        }
        std::cout << node->key << ":'" << node->value << "'";
        is_first = false;
        print_pre_order_helper(node->left, is_first);
        print_pre_order_helper(node->right, is_first);
    }

    void destroy_tree(Node* node) {
        if (node != nullptr) {
            destroy_tree(node->left);
            destroy_tree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr), count(0) {}

    ~BinarySearchTree() {
        destroy_tree(root);
    }

    size_t len() const {
        return count;
    }

    void inserir(int key, const std::string& value) {
        root = inserir_helper(root, key, value);
    }

    std::string buscar(int key) const {
        Node* result = buscar_helper(root, key);
        if (result == nullptr) {
            throw std::out_of_range("KeyError");
        }
        return result->value;
    }

    std::string remover(int key) {
        Node* target = buscar_helper(root, key);
        if (target == nullptr) {
            throw std::out_of_range("KeyError");
        }
        std::string value_to_return = target->value;
        root = remover_helper(root, key);
        count--;
        return value_to_return;
    }

    void print_pre_order() const {
        bool is_first = true;
        print_pre_order_helper(root, is_first);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    BinarySearchTree bst;
    int key;
    std::string value;

    for (int i = 0; i < 5; ++i) {
        std::cin >> key;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, value);
        bst.inserir(key, value);
    }

    char command;
    while (std::cin >> command) {
        if (command == 'P') {
            bst.print_pre_order();
            std::cout << '\n';
        } else if (command == 'L') {
            std::cout << bst.len() << '\n';
        } else if (command == 'R') {
            int key_to_remove;
            std::cin >> key_to_remove;
            try {
                std::cout << bst.remover(key_to_remove) << '\n';
            } catch (const std::out_of_range&) {
            }
        } else if (command == 'B') {
            int key_to_find;
            std::cin >> key_to_find;
            try {
                std::cout << bst.buscar(key_to_find) << '\n';
            } catch (const std::out_of_range&) {
            }
        }
    }

    return 0;
}
