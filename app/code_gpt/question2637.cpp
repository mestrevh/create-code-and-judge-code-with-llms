/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int pontos[6];
    int soma = 0;
    bool negativo = false;
    
    for (int i = 0; i < 6; i++) {
        cout << "Digite pontuacao da partida " << (i + 1) << ":\n";
        cin >> pontos[i];
        if (pontos[i] < 0) {
            negativo = true;
        }
        soma += pontos[i];
    }
    
    if (negativo) {
        cout << "Valores negativos nao sao permitidos." << endl;
    } else {
        cout << "Total de pontos: " << soma << ". O competidor esta " 
             << (soma >= 100 ? "classificado." : "desclassificado.") << endl;
    }
    
    return 0;
}
