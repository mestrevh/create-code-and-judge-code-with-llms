/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

struct EventNode {
    std::string name;
    long long year;
    EventNode* next;

    EventNode(std::string n, long long y) : name(n), year(y), next(nullptr) {}
};

void insertSorted(EventNode*& head, const std::string& name, long long year) {
    EventNode* newNode = new EventNode(name, year);

    if (head == nullptr || newNode->year < head->year || (newNode->year == head->year && newNode->name < head->name)) {
        newNode->next = head;
        head = newNode;
        return;
    }

    EventNode* current = head;
    while (current->next != nullptr && 
           (current->next->year < newNode->year || 
           (current->next->year == newNode->year && current->next->name < newNode->name))) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(EventNode* head) {
    EventNode* current = head;
    while (current != nullptr) {
        std::cout << current->year << " - " << current->name << std::endl;
        current = current->next;
    }
}

void deleteList(EventNode*& head) {
    EventNode* current = head;
    while (current != nullptr) {
        EventNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    EventNode* head = nullptr;
    std::string eventName;
    long long year;

    while (std::getline(std::cin, eventName)) {
        if (eventName.empty()) {
            continue;
        }
        
        std::cin >> year;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        insertSorted(head, eventName, year);
    }

    printList(head);

    deleteList(head);

    return 0;
}
