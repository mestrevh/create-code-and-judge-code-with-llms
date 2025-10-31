/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int pontos, soma = 0;
    for (int i = 0; i < 6; i++) {
        cin >> pontos;
        soma += pontos;
    }
    if (soma >= 100) {
        cout << "Classificado" << endl;
    } else {
        cout << "Eliminado" << endl;
    }
    return 0;
}
