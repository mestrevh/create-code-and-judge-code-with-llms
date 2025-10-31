/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Candidato {
    int numero;
    string nome;
    string partido;
    int votos;
};

int main() {
    Candidato candidatos[5];
    for (int i = 0; i < 5; ++i) {
        cin >> candidatos[i].numero;
        cin >> candidatos[i].nome;
        cin >> candidatos[i].partido;
        candidatos[i].votos = 0;
    }
    
    int voto;
    while (cin >> voto && voto != 0) {
        for (int i = 0; i < 5; ++i) {
            if (candidatos[i].numero == voto) {
                candidatos[i].votos++;
            }
        }
    }
    
    for (int i = 0; i < 5; ++i) {
        cout << candidatos[i].partido << " " 
             << candidatos[i].numero << " " 
             << candidatos[i].nome << ": " 
             << candidatos[i].votos << endl;
    }
    
    return 0;
}
