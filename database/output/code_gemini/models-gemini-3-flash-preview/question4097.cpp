/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

struct usuario {
    int idade;
    char nome[61];
    char sexo;
    char estado_civil;
    int amigos;
    int fotos;
};

void cadastraUsuario(struct usuario users[], int posicao) {
    if (!(cin >> users[posicao].idade)) return;
    cin.ignore(1000, '\n');
    cin.getline(users[posicao].nome, 61);
    cin >> users[posicao].sexo;
    cin >> users[posicao].estado_civil;
    cin >> users[posicao].amigos;
    cin >> users[posicao].fotos;
}

void imprimeUsuario(struct usuario *user) {
    cout << "Idade: " << user->idade << "\n";
    cout << "Nome: " << user->nome << "\n";
    cout << "Sexo: " << user->sexo << "\n";
    cout << "Estado Civil: " << user->estado_civil << "\n";
    cout << "Numero de amigos: " << user->amigos << "\n";
    cout << "Numero de fotos: " << user->fotos << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Digite a quantidade de usuarios:\n";
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        cout << "Digite os dados do usuario " << i << ":\n";
    }

    usuario* users = new usuario[n];
    for (int i = 0; i < n; ++i) {
        cadastraUsuario(users, i);
    }

    for (int i = 0; i < n; ++i) {
        imprimeUsuario(&users[i]);
        cout << "\n";
    }

    delete[] users;
    return 0;
}