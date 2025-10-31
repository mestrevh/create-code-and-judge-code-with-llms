/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Bandit {
    std::string name;
    int defenseStrength;
    Bandit* next;
    Bandit(const std::string& n, int fd) : name(n), defenseStrength(fd), next(nullptr) {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int fi;
    std::cin >> fi;
    
    Bandit* head = nullptr;
    Bandit* tail = nullptr;
    
    std::string name;
    int fd;
    while (std::cin >> name && name != "Fim") {
        std::cin >> fd;
        Bandit* newNode = new Bandit(name, fd);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Bandit* current = head;
    while (current != nullptr) {
        if (fi >= current->defenseStrength) {
            if (current->next != nullptr) {
                std::cout << "Conseguimos interrogar " << current->name 
                          << ", que nos entregou " << current->next->name << ".\n";
            } else {
                std::cout << "Agora sim, com a confissao de " << current->name 
                          << ", prendemos todos os canalhas.\n";
                break;
            }
        } else {
            std::cout << "Droga, a busca acabou em " << current->name << ".\n";
            break;
        }
        current = current->next;
    }
    
    current = head;
    while (current != nullptr) {
        Bandit* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}
