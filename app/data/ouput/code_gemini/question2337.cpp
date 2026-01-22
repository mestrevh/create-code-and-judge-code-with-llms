/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string data;
    Node* next;

    Node(const std::string& val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    void append(const std::string& value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void removeFirst(const std::string& value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* node_to_delete = current->next;
                current->next = node_to_delete->next;
                if (node_to_delete == tail) {
                    tail = current;
                }
                delete node_to_delete;
                return;
            }
            current = current->next;
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    LinkedList orders;
    std::string line;

    while (std::getline(std::cin, line) && line != "The End") {
        orders.append(line);
    }

    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            orders.removeFirst(line);
        }
    }

    if (orders.isEmpty()) {
        std::cout << "U gotta null pointer ma man" << std::endl;
    } else {
        orders.print();
    }

    return 0;
}
