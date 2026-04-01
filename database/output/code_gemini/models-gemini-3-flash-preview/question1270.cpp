/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct BSTNode;

struct Node {
    string name;
    bool is_dir;
    Node* parent_dir;
    BSTNode* bst_root;

    Node(string n, bool d, Node* p) : name(n), is_dir(d), parent_dir(p), bst_root(nullptr) {}
};

struct BSTNode {
    Node* file_info;
    BSTNode *left, *right;

    BSTNode(Node* info) : file_info(info), left(nullptr), right(nullptr) {}
};

void deleteBST(BSTNode* root);

void deleteNodeObject(Node* node) {
    if (!node) return;
    if (node->is_dir) {
        deleteBST(node->bst_root);
    }
    delete node;
}

void deleteBST(BSTNode* root) {
    if (!root) return;
    deleteBST(root->left);
    deleteBST(root->right);
    deleteNodeObject(root->file_info);
    delete root;
}

BSTNode* insert(BSTNode* root, Node* info, bool &exists) {
    if (!root) return new BSTNode(info);
    if (info->name < root->file_info->name) {
        root->left = insert(root->left, info, exists);
    } else if (info->name > root->file_info->name) {
        root->right = insert(root->right, info, exists);
    } else {
        exists = true;
    }
    return root;
}

Node* find_in_bst(BSTNode* root, string name) {
    if (!root) return nullptr;
    if (name == root->file_info->name) return root->file_info;
    if (name < root->file_info->name) return find_in_bst(root->left, name);
    return find_in_bst(root->right, name);
}

BSTNode* deleteBSTNodeOnly(BSTNode* root, string name) {
    if (!root) return nullptr;
    if (name < root->file_info->name) {
        root->left = deleteBSTNodeOnly(root->left, name);
    } else if (name > root->file_info->name) {
        root->right = deleteBSTNodeOnly(root->right, name);
    } else {
        if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        BSTNode* succ = root->right;
        while (succ->left) succ = succ->left;
        root->file_info = succ->file_info;
        root->right = deleteBSTNodeOnly(root->right, succ->file_info->name);
    }
    return root;
}

void run_ls(BSTNode* root) {
    if (!root) return;
    run_ls(root->left);
    cout << root->file_info->name << endl;
    run_ls(root->right);
}

void run_tree(BSTNode* bst_root, int level, const string& order);

void visit(BSTNode* bst_node, int level, const string& order) {
    if (!bst_node) return;
    for (int i = 0; i < level * 4; ++i) cout << " ";
    cout << bst_node->file_info->name << endl;
    if (bst_node->file_info->is_dir) {
        run_tree(bst_node->file_info->bst_root, level + 1, order);
    }
}

void run_tree(BSTNode* bst_root, int level, const string& order) {
    if (!bst_root) return;
    if (order == "--pre-order") {
        visit(bst_root, level, order);
        run_tree(bst_root->left, level, order);
        run_tree(bst_root->right, level, order);
    } else if (order == "--in-order") {
        run_tree(bst_root->left, level, order);
        visit(bst_root, level, order);
        run_tree(bst_root->right, level, order);
    } else if (order == "--post-order") {
        run_tree(bst_root->left, level, order);
        run_tree(bst_root->right, level, order);
        visit(bst_root, level, order);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root_dir = new Node("/", true, nullptr);
    Node* current_dir = root_dir;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string cmd;
        if (!(ss >> cmd)) continue;

        if (cmd == "cd") {
            string d;
            if (ss >> d) {
                if (d == "..") {
                    if (current_dir->parent_dir) {
                        current_dir = current_dir->parent_dir;
                    }
                } else {
                    Node* next = find_in_bst(current_dir->bst_root, d);
                    if (!next) {
                        cout << "No such file or directory" << endl;
                    } else if (!next->is_dir) {
                        cout << "Not a directory" << endl;
                    } else {
                        current_dir = next;
                    }
                }
            }
        } else if (cmd == "ls") {
            run_ls(current_dir->bst_root);
        } else if (cmd == "touch") {
            string f;
            if (ss >> f) {
                bool exists = false;
                Node* newNode = new Node(f, false, current_dir);
                current_dir->bst_root = insert(current_dir->bst_root, newNode, exists);
                if (exists) {
                    cout << "File exists" << endl;
                    delete newNode;
                }
            }
        } else if (cmd == "mkdir") {
            string d;
            if (ss >> d) {
                bool exists = false;
                Node* newNode = new Node(d, true, current_dir);
                current_dir->bst_root = insert(current_dir->bst_root, newNode, exists);
                if (exists) {
                    cout << "File exists" << endl;
                    delete newNode;
                }
            }
        } else if (cmd == "pwd") {
            if (current_dir == root_dir) cout << "/" << endl;
            else cout << current_dir->name << endl;
        } else if (cmd == "tree") {
            string arg;
            if (!(ss >> arg)) {
                cout << "Illegal option" << endl;
            } else if (arg == "--pre-order" || arg == "--in-order" || arg == "--post-order") {
                run_tree(current_dir->bst_root, 0, arg);
            } else {
                cout << "Illegal option" << endl;
            }
        } else if (cmd == "rm") {
            string f;
            if (ss >> f) {
                Node* target = find_in_bst(current_dir->bst_root, f);
                if (!target) {
                    cout << "No such file or directory" << endl;
                } else {
                    current_dir->bst_root = deleteBSTNodeOnly(current_dir->bst_root, f);
                    deleteNodeObject(target);
                }
            }
        } else {
            cout << "Command not found" << endl;
        }
    }

    return 0;
}