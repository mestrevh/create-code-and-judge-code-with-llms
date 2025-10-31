/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Pessoa {
    std::string nome;
    int horaChegada;
    int horasPermanencia;
    double porcentagem;
};

struct Node {
    Pessoa data;
    Node* next;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H;
    std::cin >> H;

    Node* head = nullptr;

    std::string nome_in;
    int horaChegada_in;
    int horasPermanencia_in;
    double porcentagem_in;

    while (std::cin >> nome_in >> horaChegada_in >> horasPermanencia_in >> porcentagem_in) {
        Pessoa novaPessoa = {nome_in, horaChegada_in, horasPermanencia_in, porcentagem_in};
        Node* newNode = new Node{novaPessoa, head};
        head = newNode;
    }

    for (int hora_atual = 1; hora_atual <= H; ++hora_atual) {
        std::string melhor_nome = "";
        double max_porcentagem = -1.0;

        Node* current = head;
        while (current != nullptr) {
            int inicio = current->data.horaChegada;
            int fim = inicio + current->data.horasPermanencia;
            
            if (hora_atual >= inicio && hora_atual < fim) {
                if (current->data.porcentagem > max_porcentagem) {
                    max_porcentagem = current->data.porcentagem;
                    melhor_nome = current->data.nome;
                }
            }
            current = current->next;
        }

        if (melhor_nome.empty()) {
            std::cout << "Não tem ninguém para Frank agora\n";
        } else {
            std::cout << "A melhor match para Frank é " << melhor_nome << "\n";
        }
    }

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
