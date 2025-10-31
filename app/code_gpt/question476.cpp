/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Personagem {
    string nome;
    int id;
    int level;
    int vida;
    int ataque;
    int defesa;
};

int main() {
    int X;
    cin >> X;
    
    Personagem personagens[X];
    
    for (int i = 0; i < X; ++i) {
        cin >> personagens[i].nome;
        cin >> personagens[i].id;
        cin >> personagens[i].level;
        cin >> personagens[i].vida;
        cin >> personagens[i].ataque;
        cin >> personagens[i].defesa;
    }
    
    for (int i = 0; i < X; ++i) {
        cout << "Nome: " << personagens[i].nome << endl;
        cout << "ID: " << personagens[i].id << endl;
        cout << "Level: " << personagens[i].level << endl;
        cout << "Vida: " << personagens[i].vida << endl;
        cout << "Ataque: " << personagens[i].ataque << endl;
        cout << "Defesa: " << personagens[i].defesa << endl;
    }
    
    return 0;
}
