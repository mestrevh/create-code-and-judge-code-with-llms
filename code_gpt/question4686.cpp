/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    queue<int> fila;
    string comando;

    while (getline(cin, comando)) {
        stringstream ss(comando);
        string acao;
        ss >> acao;

        if (acao == "push") {
            int valor;
            ss >> valor;
            fila.push(valor);
        } else if (acao == "pop") {
            if (!fila.empty()) {
                fila.pop();
            }
        } else if (acao == "sum") {
            int soma = 0;
            queue<int> temp = fila; 
            while (!temp.empty()) {
                soma += temp.front();
                temp.pop();
            }
            cout << soma << endl;
        } else if (acao == "print") {
            queue<int> temp = fila; 
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        } else if (acao == "exit") {
            break;
        }
    }
    return 0;
}
