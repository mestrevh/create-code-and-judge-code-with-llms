/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Node structure for the manual singly linked list implementation.
 * As required by the problem statement to manage tasks.
 */
struct TaskNode {
    string taskName;
    TaskNode* next;
    TaskNode(string name) : taskName(name), next(nullptr) {}
};

int main() {
    // Optimization for fast I/O in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TaskNode* head = nullptr;
    int commandCode;

    // Read command code until 0
    while (cin >> commandCode && commandCode != 0) {
        string task;
        // Skip leading whitespace/newlines and read the entire task name
        getline(cin >> ws, task);

        if (commandCode == 1) {
            // ADICIONAR: Add a new Mr. Meeseeks task to the linked list
            // Since task names are unique, we can efficiently insert at the head (O(1))
            TaskNode* newNode = new TaskNode(task);
            newNode->next = head;
            head = newNode;
            cout << "A tarefa " << task << " foi cadastrada com sucesso.\n";

        } else if (commandCode == 2) {
            // FINALIZAR: Remove the task from the linked list (O(N))
            // It is guaranteed that the task exists in the list
            TaskNode* current = head;
            TaskNode* previous = nullptr;

            while (current != nullptr) {
                if (current->taskName == task) {
                    if (previous == nullptr) {
                        head = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    delete current;
                    break;
                }
                previous = current;
                current = current->next;
            }
            cout << "A tarefa " << task << " foi finalizada e um Mr. Meeseeks se despede de nos.\n";

        } else if (commandCode == 3) {
            // BUSCAR: Search for the task in the linked list (O(N))
            TaskNode* current = head;
            bool found = false;

            while (current != nullptr) {
                if (current->taskName == task) {
                    found = true;
                    break;
                }
                current = current->next;
            }

            if (found) {
                cout << "Mr. Meeseeks: Eu sou o Mr. Meeseeks e estou fazendo a tarefa " << task << ". Olhe para mim!\n";
            } else {
                cout << "A tarefa " << task << " nao esta sendo atendida por nenhum Mr. Meeseeks.\n";
            }
        }
    }

    // Clean up allocated memory for the remaining nodes in the linked list
    while (head != nullptr) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}