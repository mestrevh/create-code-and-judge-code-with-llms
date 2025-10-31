/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string canos[3];
    cin >> canos[0] >> canos[1] >> canos[2];

    string resposta = "Vou em frente";
    string direcao[] = {"Direita", "Meio", "Esquerda"};

    for (int i = 0; i < 3; i++) {
        if (canos[i][0] == 'F' && canos[i].back() == 'r') {
            resposta = direcao[i];
            break;
        }
    }

    cout << resposta << endl;
    return 0;
}
