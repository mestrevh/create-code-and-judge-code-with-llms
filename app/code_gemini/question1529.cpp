/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

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
            Node* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    void push_back(const std::string& data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    bool find_and_remove(const std::string& data) {
        if (head == nullptr) {
            return false;
        }

        if (head->data == data) {
            Node* to_delete = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete to_delete;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return false;
        }

        Node* to_delete = current->next;
        current->next = to_delete->next;
        if (to_delete == tail) {
            tail = current;
        }
        delete to_delete;
        return true;
    }

    void print() {
        Node* current = head;
        bool first = true;
        while (current != nullptr) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << current->data;
            first = false;
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    LinkedList quiver;
    std::string line;

    while (std::getline(std::cin, line) && line != "Recarga feita") {
        quiver.push_back(line);
    }

    while (std::getline(std::cin, line) && line != "Fim da simulacao") {
        if (quiver.find_and_remove(line)) {
            std::cout << "Flecha disparada\n";
        } else {
            std::cout << "Flecha nao encontrada\n";
        }
    }

    std::cout << "Flechas que sobraram: ";
    quiver.print();

    return 0;
}
