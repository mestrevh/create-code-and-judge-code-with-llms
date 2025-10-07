/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string cidade, melhorDestino;
    int distancia, melhorDistancia = 0;
    double passagem, orcamento = 300.0;

    while (true) {
        getline(cin, cidade);
        if (strcasecmp(cidade.c_str(), "fim") == 0) break;
        
        cin >> distancia >> passagem;
        cin.ignore();

        if (passagem * 2 <= orcamento && distancia > melhorDistancia) {
            melhorDistancia = distancia;
            melhorDestino = cidade;
        }
    }

    if (melhorDestino.empty()) {
        cout << "SEM DESTINO" << endl;
    } else {
        transform(melhorDestino.begin(), melhorDestino.end(), melhorDestino.begin(), ::toupper);
        cout << melhorDestino << endl;
    }

    return 0;
}
