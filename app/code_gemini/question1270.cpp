/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <utility>

// Forward declarations
struct FSNode;
struct Directory;
struct BSTNode;

void delete_bst(BSTNode* node);

// Filesystem Node base class
struct FSNode {
    std::string name;
    bool is_dir;

    FSNode(std::string n, bool d) : name(std::move(n)), is_dir(d) {}
    virtual ~FSNode() = default;
};

// File class
struct File : public FSNode {
    explicit File(std::string n) : FSNode(std::move(n), false) {}
};

// Directory class
struct Directory : public FSNode {
    BSTNode* children_root = nullptr;
    Directory* parent;

    Directory(std::string n, Directory* p) : FSNode(std::move(n), true), parent(p) {}
    ~Directory() override {
        delete_bst(children_root);
    }
};

// BST Node class
struct BSTNode {
    FSNode* data;
    BSTNode *left = nullptr, *right = nullptr;

    explicit BSTNode(FSNode* d) : data(d) {}
    ~BSTNode() {
        delete data;
    }
};

// --- BST Helper Functions ---

BSTNode* find(BSTNode* node, const std::string& name) {
    if (node == nullptr || node->data->name == name) {
        return node;
    }
    if (name < node->data->name) {
        return find(node->left, name);
    } else {
        return find(node->right, name);
    }
}

BSTNode* insert(BSTNode* node, FSNode* data) {
    if (node == nullptr) {
        return new BSTNode(data);
    }
    if (data->name < node->data->name) {
        node->left = insert(node->left, data);
    } else if (data->name > node->data->name) {
        node->right = insert(node->right, data);
    }
    return node;
}

BSTNode* find_min(BSTNode* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode* remove(BSTNode* node, const std::string& name) {
    if (node == nullptr) return node;

    if (name < node->data->name) {
        node->left = remove(node->left, name);
    } else if (name > node->data->name) {
        node->right = remove(node->right, name);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        BSTNode* successor = find_min(node->right);
        FSNode* temp_data = node->data;
        node->data = successor->data;
        successor->data = temp_data;
        node->right = remove(node->right, successor->data->name);
    }
    return node;
}

void delete_bst(BSTNode* node) {
    if (node == nullptr) return;
    delete_bst(node->left);
    delete_bst(node->right);
    delete node;
}

// --- BST Traversal Functions ---

void traverse_pre_order(BSTNode* node, const std::function<void(FSNode*)>& visit) {
    if (node == nullptr) return;
    visit(node->data);
    traverse_pre_order(node->left, visit);
    traverse_pre_order(node->right, visit);
}

void traverse_in_order(BSTNode* node, const std::function<void(FSNode*)>& visit) {
    if (node == nullptr) return;
    traverse_in_order(node->left, visit);
    visit(node->data);
    traverse_in_order(node->right, visit);
}

void traverse_post_order(BSTNode* node, const std::function<void(FSNode*)>& visit) {
    if (node == nullptr) return;
    traverse_post_order(node->left, visit);
    traverse_post_order(node->right, visit);
    visit(node->data);
}

// --- Global State & Command Handlers ---

Directory* root_dir = nullptr;
Directory* current_dir = nullptr;

void handle_pwd() {
    if (current_dir == root_dir) {
        std::cout << "/\n";
    } else {
        std::cout << current_dir->name << "\n";
    }
}

void handle_mkdir(const std::string& name) {
    if (find(current_dir->children_root, name) != nullptr) {
        std::cout << "File exists\n";
    } else {
        auto* new_dir = new Directory(name, current_dir);
        current_dir->children_root = insert(current_dir->children_root, new_dir);
    }
}

void handle_touch(const std::string& name) {
    if (find(current_dir->children_root, name) != nullptr) {
        std::cout << "File exists\n";
    } else {
        auto* new_file = new File(name);
        current_dir->children_root = insert(current_dir->children_root, new_file);
    }
}

void handle_ls() {
    traverse_in_order(current_dir->children_root, [](FSNode* node) {
        std::cout << node->name << "\n";
    });
}

void handle_cd(const std::string& name) {
    if (name == "..") {
        if (current_dir->parent != nullptr) {
            current_dir = current_dir->parent;
        }
    } else {
        BSTNode* target_node = find(current_dir->children_root, name);
        if (target_node == nullptr) {
            std::cout << "No such file or directory\n";
        } else if (!target_node->data->is_dir) {
            std::cout << "Not a directory\n";
        } else {
            current_dir = static_cast<Directory*>(target_node->data);
        }
    }
}

void handle_rm(const std::string& name) {
    if (find(current_dir->children_root, name) == nullptr) {
        std::cout << "No such file or directory\n";
    } else {
        current_dir->children_root = remove(current_dir->children_root, name);
    }
}

void execute_tree_on_dir(Directory* dir, int indent, const std::string& order) {
    auto visitor = [&](FSNode* node_to_print) {
        for (int i = 0; i < indent; ++i) std::cout << " ";
        std::cout << node_to_print->name << "\n";
        if (node_to_print->is_dir) {
            execute_tree_on_dir(static_cast<Directory*>(node_to_print), indent + 4, order);
        }
    };

    if (order == "--pre-order") {
        traverse_pre_order(dir->children_root, visitor);
    } else if (order == "--in-order") {
        traverse_in_order(dir->children_root, visitor);
    } else if (order == "--post-order") {
        traverse_post_order(dir->children_root, visitor);
    }
}

void handle_tree(const std::string& order) {
    if (order != "--pre-order" && order != "--in-order" && order != "--post-order") {
        std::cout << "Illegal option\n";
        return;
    }
    execute_tree_on_dir(current_dir, 0, order);
}

// --- Main Function ---

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    root_dir = new Directory("/", nullptr);
    current_dir = root_dir;

    std::string line;
    while (getline(std::cin, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string command;
        ss >> command;
        
        std::string arg1;
        if (ss >> arg1) {
            if (command == "cd") handle_cd(arg1);
            else if (command == "touch") handle_touch(arg1);
            else if (command == "mkdir") handle_mkdir(arg1);
            else if (command == "tree") handle_tree(arg1);
            else if (command == "rm") handle_rm(arg1);
            else std::cout << "Command not found\n";
        } else {
            if (command == "ls") handle_ls();
            else if (command == "pwd") handle_pwd();
            else std::cout << "Command not found\n";
        }
    }
    delete root_dir;
    return 0;
}
