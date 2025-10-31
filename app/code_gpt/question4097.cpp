/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct usuario {
    int idade;
    string nome;
    char sexo;
    char estadoCivil;
    int numAmigos;
    int numFotos;
};

void cadastraUsuario(usuario users[], int posicao) {
    cout << "Digite os dados do usuario " << posicao + 1 << ":\n";
    cin >> users[posicao].idade;
    cin.ignore();
    getline(cin, users[posicao].nome);
    cin >> users[posicao].sexo;
    cin >> users[posicao].estadoCivil;
    cin >> users[posicao].numAmigos;
    cin >> users[posicao].numFotos;
}

void imprimeUsuario(usuario *user) {
    cout << "Idade: " << user->idade << endl;
    cout << "Nome: " << user->nome << endl;
    cout << "Sexo: " << user->sexo << endl;
    cout << "Estado Civil: " << user->estadoCivil << endl;
    cout << "Numero de amigos: " << user->numAmigos << endl;
    cout << "Numero de fotos: " << user->numFotos << endl << endl;
}

int main() {
    int n;
    cout << "Digite a quantidade de usuarios:" << endl;
    cin >> n;
    usuario users[n];
    
    for (int i = 0; i < n; i++) {
        cadastraUsuario(users, i);
    }
    
    for (int i = 0; i < n; i++) {
        imprimeUsuario(&users[i]);
    }

    return 0;
}
