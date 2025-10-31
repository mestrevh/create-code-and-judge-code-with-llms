/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Node {
    std::string nome;
    int nota;
    Node* proximo;

    Node(const std::string& n, int s) : nome(n), nota(s), proximo(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    ~SortedLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->proximo;
            delete temp;
        }
    }

    void inserir(const std::string& nome, int nota) {
        Node* novo_no = new Node(nome, nota);

        if (head == nullptr || nota > head->nota) {
            novo_no->proximo = head;
            head = novo_no;
        } else {
            Node* atual = head;
            while (atual->proximo != nullptr && atual->proximo->nota >= nota) {
                atual = atual->proximo;
            }
            novo_no->proximo = atual->proximo;
            atual->proximo = novo_no;
        }
        std::cout << nome << " foi inserido no sistema! Sua nota e de " << nota << "." << std::endl;
    }

    void imprimir() const {
        Node* atual = head;
        while (atual != nullptr) {
            std::cout << atual->nome << " " << atual->nota << std::endl;
            atual = atual->proximo;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    SortedLinkedList sistema;
    std::string comando;

    while (std::cin >> comando && comando != "sair") {
        if (comando == "inserir") {
            std::string nome;
            int nota;
            std::cin >> nome >> nota;
            sistema.inserir(nome, nota);
        } else if (comando == "imprimir") {
            sistema.imprimir();
        }
    }

    return 0;
}
