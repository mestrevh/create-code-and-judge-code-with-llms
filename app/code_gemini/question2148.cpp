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
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    void append(const std::string& val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string temp;
    std::getline(std::cin, temp);

    LinkedList prereq_list;
    for (int i = 0; i < n; ++i) {
        std::string disciplina;
        std::getline(std::cin, disciplina);
        prereq_list.append(disciplina);
    }

    std::string query;
    while (std::getline(std::cin, query)) {
        if (query.empty()) {
            continue;
        }

        Node* current = prereq_list.head;
        std::vector<std::string> prerequisites;
        bool found = false;

        while (current != nullptr) {
            if (current->data == query) {
                found = true;
                break;
            }
            prerequisites.push_back(current->data);
            current = current->next;
        }

        if (found) {
            if (prerequisites.empty()) {
                std::cout << query << " podera ser cursada esse periodo.\n";
            } else {
                std::cout << query << " podera ser cursada depois de " << prerequisites.size() << " periodos, depois de ter passado por: ";
                for (size_t i = 0; i < prerequisites.size(); ++i) {
                    std::cout << prerequisites[i];
                    if (prerequisites.size() > 1 && i == prerequisites.size() - 2) {
                        std::cout << " e ";
                    } else if (i < prerequisites.size() - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << ".\n";
            }
        } else {
            std::cout << query << " nao pode ser cursada nessa cadeia de pre-requisitos.\n";
        }
    }

    return 0;
}
