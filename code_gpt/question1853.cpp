/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <memory>

struct TaskNode {
    std::string task;
    std::unique_ptr<TaskNode> next;
};

class TaskList {
private:
    std::unique_ptr<TaskNode> head;

public:
    TaskList() : head(nullptr) {}

    void addTask(const std::string& task) {
        auto newNode = std::make_unique<TaskNode>();
        newNode->task = task;
        newNode->next = std::move(head);
        head = std::move(newNode);
        std::cout << "A tarefa " << task << " foi cadastrada com sucesso." << std::endl;
    }

    void finishTask(const std::string& task) {
        TaskNode* current = head.get();
        TaskNode* previous = nullptr;

        while (current) {
            if (current->task == task) {
                if (previous) {
                    previous->next = std::move(current->next);
                } else {
                    head = std::move(current->next);
                }
                std::cout << "A tarefa " << task << " foi finalizada e um Mr. Meeseeks se despede de nos." << std::endl;
                return;
            }
            previous = current;
            current = current->next.get();
        }
    }

    void searchTask(const std::string& task) {
        TaskNode* current = head.get();
        
        while (current) {
            if (current->task == task) {
                std::cout << "Mr. Meeseeks: Eu sou o Mr. Meeseeks e estou fazendo a tarefa " << task << ". Olhe para mim!" << std::endl;
                return;
            }
            current = current->next.get();
        }
        std::cout << "A tarefa " << task << " nao esta sendo atendida por nenhum Mr. Meeseeks." << std::endl;
    }
};

int main() {
    TaskList tasks;
    int command;
    std::string task;

    while (true) {
        std::cin >> command;
        if (command == 0) break;
        std::cin.ignore();
        std::getline(std::cin, task);

        switch (command) {
            case 1:
                tasks.addTask(task);
                break;
            case 2:
                tasks.finishTask(task);
                break;
            case 3:
                tasks.searchTask(task);
                break;
        }
    }

    return 0;
}
