/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Node {
    std::string task;
    Node* next;
};

Node* head = nullptr;

void adicionar(const std::string& task_name) {
    Node* newNode = new Node;
    newNode->task = task_name;
    newNode->next = head;
    head = newNode;
    std::cout << "A tarefa " << task_name << " foi cadastrada com sucesso." << std::endl;
}

void buscar(const std::string& task_name) {
    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->task == task_name) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        std::cout << "Mr. Meeseeks: Eu sou o Mr. Meeseeks e estou fazendo a tarefa " << task_name << ". Olhe para mim!" << std::endl;
    } else {
        std::cout << "A tarefa " << task_name << " nao esta sendo atendida por nenhum Mr. Meeseeks." << std::endl;
    }
}

void finalizar(const std::string& task_name) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->task == task_name) {
        head = temp->next;
        delete temp;
        std::cout << "A tarefa " << task_name << " foi finalizada e um Mr. Meeseeks se despede de nos." << std::endl;
        return;
    }

    while (temp != nullptr && temp->task != task_name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;
    }

    prev->next = temp->next;
    delete temp;
    std::cout << "A tarefa " << task_name << " foi finalizada e um Mr. Meeseeks se despede de nos." << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int command;
    while (std::cin >> command && command != 0) {
        std::cin.ignore();
        std::string task_name;
        std::getline(std::cin, task_name);

        switch (command) {
            case 1:
                adicionar(task_name);
                break;
            case 2:
                finalizar(task_name);
                break;
            case 3:
                buscar(task_name);
                break;
        }
    }

    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }

    return 0;
}
