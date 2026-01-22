/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Usuario {
    int idade;
    string nome;
    char sexo;
    char estadoCivil;
    int numeroAmigos;
    int numeroFotos;
};

int main() {
    int n;
    cin >> n;
    Usuario usuarios[n];

    for (int i = 0; i < n; i++) {
        cin >> usuarios[i].idade;
        cin.ignore();
        getline(cin, usuarios[i].nome);
        cin >> usuarios[i].sexo >> usuarios[i].estadoCivil >> usuarios[i].numeroAmigos >> usuarios[i].numeroFotos;
    }

    for (int i = 0; i < n; i++) {
        cout << "Idade: " << usuarios[i].idade << endl;
        cout << "Nome: " << usuarios[i].nome << endl;
        cout << "Sexo: " << usuarios[i].sexo << endl;
        cout << "Estado Civil: " << usuarios[i].estadoCivil << endl;
        cout << "Numero de amigos: " << usuarios[i].numeroAmigos << endl;
        cout << "Numero de fotos: " << usuarios[i].numeroFotos << endl;
        if (i < n - 1) cout << endl;
    }
    
    return 0;
}
