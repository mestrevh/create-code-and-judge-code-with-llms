/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string inverter(string nome) {
    if (nome.empty()) return nome;
    for (int i = 0; i < (int)nome.length(); i++) {
        nome[i] = (char)tolower((unsigned char)nome[i]);
    }
    reverse(nome.begin(), nome.end());
    nome[0] = (char)toupper((unsigned char)nome[0]);
    return nome;
}

void tratramento(char local, int tipo, string jogador) {
    if (local == 'c') {
        cout << inverter(jogador) << endl;
    } else if (local == 'a') {
        if (tipo == 1) {
            if (!jogador.empty()) {
                char last = jogador.back();
                cout << jogador;
                for (int i = 0; i < 4; i++) {
                    cout << last;
                }
                cout << endl;
            } else {
                cout << endl;
            }
        } else {
            cout << jogador << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char local;
    int tipo;
    string jogador;

    if (cin >> local >> tipo) {
        getline(cin >> ws, jogador);
        tratramento(local, tipo, jogador);
    }

    return 0;
}