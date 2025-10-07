/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct Node {
    string disciplina;
    Node* next;
    Node(string d) : disciplina(d), next(nullptr) {}
};

class ListaEncadeada {
    Node* head;
public:
    ListaEncadeada() : head(nullptr) {}

    void inserir(string d) {
        Node* novo = new Node(d);
        novo->next = head;
        head = novo;
    }

    int encontrar(string d, vector<string>& pre_requisitos) {
        Node* atual = head;
        int pos = 0;
        while (atual) {
            if (atual->disciplina == d) {
                return pos;
            }
            pre_requisitos.push_back(atual->disciplina);
            atual = atual->next;
            pos++;
        }
        return -1;
    }

    void liberar() {
        Node* atual = head;
        while (atual) {
            Node* temp = atual;
            atual = atual->next;
            delete temp;
        }
    }
};

int main() {
    int N;
    cin >> N;
    ListaEncadeada lista;
    string disciplina;

    for (int i = 0; i < N; i++) {
        cin >> disciplina;
        lista.inserir(disciplina);
    }

    vector<string> disciplinasDesejadas;
    while (cin >> disciplina) {
        disciplinasDesejadas.push_back(disciplina);
    }

    for (const string& d : disciplinasDesejadas) {
        vector<string> pre_requisitos;
        int pos = lista.encontrar(d, pre_requisitos);
        
        if (pos == -1) {
            cout << d << " nao pode ser cursada nessa cadeia de pre-requisitos." << endl;
        } else if (pos == 0) {
            cout << d << " podera ser cursada esse periodo." << endl;
        } else {
            cout << d << " podera ser cursada depois de " << pos << " periodos, depois de ter passado por: ";
            for (int i = 0; i < pos; i++) {
                cout << pre_requisitos[i];
                if (i < pos - 1) cout << ", ";
            }
            cout << "." << endl;
        }
    }

    lista.liberar();
    return 0;
}
