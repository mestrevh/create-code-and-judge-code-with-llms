/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

struct Node {
    std::string aluno;
    Node* next;
    Node(const std::string& a) : aluno(a), next(nullptr) {}
};

class Cadeira {
public:
    std::string nome;
    Node* head;

    Cadeira(const std::string& n) : nome(n), head(nullptr) {}

    void matricula(const std::string& aluno) {
        Node* newNode = new Node(aluno);
        newNode->next = head;
        head = newNode;
    }

    void cancelamento(const std::string& aluno) {
        Node** current = &head;
        while (*current) {
            if ((*current)->aluno == aluno) {
                Node* temp = *current;
                *current = (*current)->next;
                delete temp;
                return;
            }
            current = &((*current)->next);
        }
    }

    int contarAlunos() const {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    std::unordered_map<std::string, Cadeira*> cadeiras = {
        {"Algoritmo", new Cadeira("Algoritmo")},
        {"SD", new Cadeira("SD")},
        {"Fisica", new Cadeira("Fisica")},
        {"Logica", new Cadeira("Logica")},
        {"Estatistica", new Cadeira("Estatistica")}
    };

    std::string linha;
    while (getline(std::cin, linha) && !linha.empty()) {
        size_t pos = linha.find(' ');
        std::string cadeiraNome = linha.substr(0, pos);
        std::string alunoNome = linha.substr(pos + 1);
        cadeiras[cadeiraNome]->matricula(alunoNome);
    }

    getline(std::cin, linha); // ignore the blank line

    while (getline(std::cin, linha) && !linha.empty()) {
        size_t pos = linha.find(' ');
        std::string cadeiraNome = linha.substr(0, pos);
        std::string alunoNome = linha.substr(pos + 1);
        cadeiras[cadeiraNome]->cancelamento(alunoNome);
    }

    for (const auto& cadeira : cadeiras) {
        std::cout << "Estao matriculados na turma de " << cadeira.second->nome 
                  << " " << cadeira.second->contarAlunos() << " aluno(os)" << std::endl;
    }

    for (const auto& cadeira : cadeiras) {
        delete cadeira.second;
    }

    return 0;
}
