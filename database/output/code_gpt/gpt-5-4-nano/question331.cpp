/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct User {
    int idade;
    string nome;
    char sexo;
    char estadoCivil;
    int amigos;
    int fotos;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<User> users(n);
    for (int i = 0; i < n; i++) {
        cin >> users[i].idade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, users[i].nome);
        cin >> users[i].sexo;
        cin >> users[i].estadoCivil;
        cin >> users[i].amigos;
        cin >> users[i].fotos;
    }

    for (int i = 0; i < n; i++) {
        cout << "Idade: " << users[i].idade << "\n";
        cout << "Nome: " << users[i].nome << "\n";
        cout << "Sexo: " << users[i].sexo << "\n";
        cout << "Estado Civil: " << users[i].estadoCivil << "\n";
        cout << "Numero de amigos: " << users[i].amigos << "\n";
        cout << "Numero de fotos: " << users[i].fotos << "\n";
        if (i + 1 < n) cout << "\n";
    }
    return 0;
}