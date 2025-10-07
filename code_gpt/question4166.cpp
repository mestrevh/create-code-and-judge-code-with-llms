/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

void inverter(string& nome) {
    reverse(nome.begin(), nome.end());
}

void tratamento(char local, char tipo, string jogador) {
    if (local == 'c') {
        inverter(jogador);
        if (tipo == '1') {
            jogador += string(5, jogador.back());
        }
    } else if (local == 'a' && tipo == '1') {
        jogador += string(5, jogador.back());
    }
    cout << jogador << endl;
}

int main() {
    char local, tipo;
    string jogador;
    cin >> local >> tipo;
    cin.ignore();
    getline(cin, jogador);
    tratamento(local, tipo, jogador);
    return 0;
}
