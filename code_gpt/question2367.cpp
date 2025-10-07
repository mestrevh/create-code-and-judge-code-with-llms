/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

class Node {
public:
    std::string name;
    Node* next;
    Node(std::string name) : name(name), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(std::string name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    void remove(std::string name) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
        }
    }

    bool exists(std::string name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) return true;
            current = current->next;
        }
        return false;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->name << std::endl;
            current = current->next;
        }
    }
};

int main() {
    int x;
    std::cin >> x;
    LinkedList team;
    std::string instruction, name;
    for (int i = 0; i < x; i++) {
        std::cin >> instruction >> name;
        if (instruction == "ENTRA") {
            team.insert(name);
        } else if (instruction == "SAI") {
            team.remove(name);
        } else if (instruction == "PRESENTE") {
            if (team.exists(name)) {
                std::cout << name << " esta no time." << std::endl;
            } else {
                std::cout << name << " nao esta no time." << std::endl;
            }
        }
    }
    team.print();
    return 0;
}
