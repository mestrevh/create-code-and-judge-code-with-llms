/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct usuario {
    int idade;
    string nome;
    char sexo;
    char estadoCivil;
    int amigos;
    int fotos;
};

void cadastraUsuario(usuario users[], int posicao) {
    cin >> users[posicao].idade;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, users[posicao].nome);
    cin >> users[posicao].sexo;
    cin >> users[posicao].estadoCivil;
    cin >> users[posicao].amigos;
    cin >> users[posicao].fotos;
}

void imprimeUsuario(usuario *user) {
    cout << "Idade: " << user->idade << "\n";
    cout << "Nome: " << user->nome << "\n";
    cout << "Sexo: " << user->sexo << "\n";
    cout << "Estado Civil: " << user->estadoCivil << "\n";
    cout << "Numero de amigos: " << user->amigos << "\n";
    cout << "Numero de fotos: " << user->fotos << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Digite a quantidade de usuarios: ";
    cin >> n;

    usuario *users = new usuario[n];

    for (int i = 0; i < n; i++) {
        cout << "Digite os dados do usuario " << (i + 1) << ": ";
        cadastraUsuario(users, i);
    }

    for (int i = 0; i < n; i++) {
        imprimeUsuario(&users[i]);
        if (i != n - 1) cout << "\n";
    }

    cout << "\n";
    delete[] users;
    return 0;
}