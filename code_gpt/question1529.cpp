/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string tipo;
    Node* next;
};

class ListaEncadeada {
public:
    Node* head;
    ListaEncadeada() : head(nullptr) {}

    void adicionar(const string& tipo) {
        Node* novo = new Node{tipo, head};
        head = novo;
    }

    bool remover(const string& tipo) {
        Node** atual = &head;
        while (*atual) {
            if ((*atual)->tipo == tipo) {
                Node* temp = *atual;
                *atual = (*atual)->next;
                delete temp;
                return true;
            }
            atual = &((*atual)->next);
        }
        return false;
    }

    void mostrar() {
        Node* atual = head;
        cout << "Flechas que sobraram: ";
        while (atual) {
            cout << atual->tipo << " ";
            atual = atual->next;
        }
        cout << endl;
    }

    ~ListaEncadeada() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ListaEncadeada aljava;
    string tipo;

    while (true) {
        getline(cin, tipo);
        if (tipo == "Recarga feita") break;
        aljava.adicionar(tipo);
    }

    while (true) {
        getline(cin, tipo);
        if (tipo == "Fim da simulacao") break;
        if (aljava.remover(tipo)) {
            cout << "Flecha disparada" << endl;
        } else {
            cout << "Flecha nao encontrada" << endl;
        }
    }

    aljava.mostrar();
    return 0;
}
