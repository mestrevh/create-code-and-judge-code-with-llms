/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Node {
    std::string name;
    Node* next;

    Node(const std::string& n) : name(n), next(nullptr) {}
};

class LinkedQueue {
private:
    Node* front_node;
    Node* rear_node;
    int count;

public:
    LinkedQueue() : front_node(nullptr), rear_node(nullptr), count(0) {}

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const std::string& name) {
        Node* new_node = new Node(name);
        if (isEmpty()) {
            front_node = rear_node = new_node;
        } else {
            rear_node->next = new_node;
            rear_node = new_node;
        }
        count++;
    }

    std::string dequeue() {
        if (isEmpty()) {
            return "";
        }
        std::string name = front_node->name;
        Node* temp = front_node;
        front_node = front_node->next;
        if (front_node == nullptr) {
            rear_node = nullptr;
        }
        delete temp;
        count--;
        return name;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    LinkedQueue fila_ru;
    LinkedQueue fila_area2;

    std::string comida_ru;
    std::string comida_area2;

    std::string line;
    
    std::getline(std::cin, line);
    comida_ru = line.substr(line.find(":") + 1);

    std::getline(std::cin, line);
    comida_area2 = line.substr(line.find(":") + 1);

    std::string command;
    while (std::getline(std::cin, command)) {
        if (command.empty()) {
            continue;
        }

        if (command.substr(0, 5) == "SAIU:") {
            std::string local = command.substr(5);
            if (local == "RU") {
                if (!fila_ru.isEmpty()) {
                    std::string nome = fila_ru.dequeue();
                    std::cout << nome << " almocou no RU e esta voltando pra aula\n";
                } else {
                    std::cout << "Nao ha mais ninguem para comer aqui\n";
                }
            } else if (local == "AREA2") {
                if (!fila_area2.isEmpty()) {
                    std::string nome = fila_area2.dequeue();
                    std::cout << nome << " almocou na Area 2 e esta voltando pra aula\n";
                } else {
                    std::cout << "Nao ha mais ninguem para comer aqui\n";
                }
            }
        } else {
            std::string nome_pessoa;
            std::string comida_favorita;
            size_t colon_pos = command.find(":");

            if (colon_pos != std::string::npos) {
                nome_pessoa = command.substr(0, colon_pos);
                comida_favorita = command.substr(colon_pos + 1);
            } else {
                nome_pessoa = command;
                comida_favorita = "";
            }

            bool prefere_ru = (!comida_favorita.empty() && comida_favorita == comida_ru);
            bool prefere_area2 = (!comida_favorita.empty() && comida_favorita == comida_area2);

            if (prefere_ru) {
                fila_ru.enqueue(nome_pessoa);
                std::cout << nome_pessoa << " foi para a fila do RU\n";
            } else if (prefere_area2) {
                fila_area2.enqueue(nome_pessoa);
                std::cout << nome_pessoa << " foi para a fila da Area 2\n";
            } else {
                if (fila_ru.size() < fila_area2.size()) {
                    fila_ru.enqueue(nome_pessoa);
                    std::cout << nome_pessoa << " foi para a fila do RU\n";
                } else {
                    fila_area2.enqueue(nome_pessoa);
                    std::cout << nome_pessoa << " foi para a fila da Area 2\n";
                }
            }
        }
    }

    return 0;
}
