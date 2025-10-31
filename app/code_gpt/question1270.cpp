/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class FileSystem;

class Node {
public:
    std::string name;
    bool isFile;
    std::map<std::string, Node*> children;

    Node(std::string name, bool isFile) : name(name), isFile(isFile) {}
};

class FileSystem {
private:
    Node* root;
    Node* current;

    void printTree(Node* node, int level, const std::string& order) {
        if (order == "--pre-order") {
            printNode(node, level);
        }
        for (auto& it : node->children) {
            printTree(it.second, level + 1, order);
        }
        if (order == "--in-order") {
            printNode(node, level);
        }
        if (order == "--post-order") {
            printTreePost(node, level);
        }
    }
    
    void printTreePost(Node* node, int level) {
        for (auto& it : node->children) {
            printTreePost(it.second, level + 1);
        }
        printNode(node, level);
    }

    void printNode(Node* node, int level) {
        std::cout << std::string(level * 4, ' ') << node->name << std::endl;
    }

public:
    FileSystem() {
        root = new Node("/", false);
        current = root;
    }

    void cd(std::string name) {
        if (name == "..") {
            if (current->name != "/") {
                current = root; // Simplificação para demo
            }
        } else if (current->children.count(name) && !current->children[name]->isFile) {
            current = current->children[name];
        } else if (current->children.count(name) && current->children[name]->isFile) {
            std::cout << "Not a directory\n";
        } else {
            std::cout << "No such file or directory\n";
        }
    }

    void ls() {
        std::vector<std::string> files;
        for (auto& it : current->children) {
            files.push_back(it.first);
        }
        std::sort(files.begin(), files.end());
        for (const auto& file : files) {
            std::cout << file << std::endl;
        }
    }

    void touch(std::string name) {
        if (current->children.count(name)) {
            std::cout << "File exists\n";
        } else {
            current->children[name] = new Node(name, true);
        }
    }

    void mkdir(std::string name) {
        if (current->children.count(name)) {
            std::cout << "File exists\n";
        } else {
            current->children[name] = new Node(name, false);
        }
    }

    void pwd() {
        std::cout << current->name << std::endl;
    }

    void tree(std::string arg) {
        if (arg == "--pre-order" || arg == "--in-order" || arg == "--post-order") {
            printTree(current, 0, arg);
        } else {
            std::cout << "Illegal option\n";
        }
    }

    void rm(std::string name) {
        if (current->children.count(name)) {
            delete current->children[name];
            current->children.erase(name);
        } else {
            std::cout << "No such file or directory\n";
        }
    }

    void executeCommand(const std::string& command) {
        size_t pos = command.find(" ");
        std::string cmd = command.substr(0, pos);
        std::string arg = (pos == std::string::npos) ? "" : command.substr(pos + 1);
        
        if (cmd == "cd") {
            cd(arg);
        } else if (cmd == "ls") {
            ls();
        } else if (cmd == "touch") {
            touch(arg);
        } else if (cmd == "mkdir") {
            mkdir(arg);
        } else if (cmd == "pwd") {
            pwd();
        } else if (cmd == "tree") {
            tree(arg);
        } else if (cmd == "rm") {
            rm(arg);
        } else {
            std::cout << "Command not found\n";
        }
    }
};

int main() {
    FileSystem fs;
    std::string command;
    while (std::getline(std::cin, command)) {
        fs.executeCommand(command);
    }
    return 0;
}
