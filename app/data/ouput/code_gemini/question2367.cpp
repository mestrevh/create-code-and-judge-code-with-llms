/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

class ListaJogadores {
private:
    struct Node {
        std::string nome;
        Node* proximo;

        Node(const std::string& n) : nome(n), proximo(nullptr) {}
    };

    Node* cabeca;

public:
    ListaJogadores() : cabeca(nullptr) {}

    ~ListaJogadores() {
        Node* atual = cabeca;
        while (atual != nullptr) {
            Node* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }

    void inserir(const std::string& nome) {
        Node* novoNode = new Node(nome);
        if (cabeca == nullptr) {
            cabeca = novoNode;
        } else {
            Node* atual = cabeca;
            while (atual->proximo != nullptr) {
                atual = atual->proximo;
            }
            atual->proximo = novoNode;
        }
    }

    void remover(const std::string& nome) {
        if (cabeca == nullptr) {
            return;
        }

        if (cabeca->nome == nome) {
            Node* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
            return;
        }

        Node* anterior = cabeca;
        Node* atual = cabeca->proximo;
        while (atual != nullptr) {
            if (atual->nome == nome) {
                anterior->proximo = atual->proximo;
                delete atual;
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }
    }

    bool existe(const std::string& nome) {
        Node* atual = cabeca;
        while (atual != nullptr) {
            if (atual->nome == nome) {
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }

    void imprimir() const {
        Node* atual = cabeca;
        while (atual != nullptr) {
            std::cout << atual->nome << "\n";
            atual = atual->proximo;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    ListaJogadores time;
    std::string instrucao, nome;

    for (int i = 0; i < x; ++i) {
        std::cin >> instrucao >> nome;

        if (instrucao == "ENTRA") {
            time.inserir(nome);
        } else if (instrucao == "SAI") {
            time.remover(nome);
        } else if (instrucao == "PRESENTE") {
            if (time.existe(nome)) {
                std::cout << nome << " esta no time.\n";
            } else {
                std::cout << nome << " nao esta no time.\n";
            }
        }
    }

    time.imprimir();

    return 0;
}
