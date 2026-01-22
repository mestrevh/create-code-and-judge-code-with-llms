/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

class FilaCircular {
    vector<int> fila;
    int frente, tras, tamanho, count;

public:
    FilaCircular(int size) : tamanho(size), frente(0), tras(0), count(0) {
        fila.resize(size, -1);
    }

    void inserir(int valor) {
        if (count == tamanho - 1) {
            cout << "Fila cheia" << endl;
            return;
        }
        fila[tras] = valor;
        tras = (tras + 1) % tamanho;
        count++;
        imprimirFila();
    }

    void remover() {
        if (count == 0) {
            cout << "Fila vazia" << endl;
            return;
        }
        cout << fila[frente] << endl;
        fila[frente] = -1;
        frente = (frente + 1) % tamanho;
        count--;
        imprimirFila();
    }

    void imprimirFila() {
        for (int i = 0; i < tamanho; i++) {
            if (fila[i] == -1) cout << "- ";
            else cout << fila[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cin >> size;
    FilaCircular fila(size);
    
    char comando;
    while (true) {
        cin >> comando;
        if (comando == 'F') {
            cout << "Saindo..." << endl;
            break;
        }
        if (comando == 'E') {
            int valor;
            cin >> valor;
            fila.inserir(valor);
        } else if (comando == 'D') {
            fila.remover();
        }
    }
    return 0;
}
