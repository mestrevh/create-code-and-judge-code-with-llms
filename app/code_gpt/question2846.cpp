/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double valor;
    int quantidade;
    double total = 0;
    int presentesTroca = 0;

    cout << "Insira a quantidade e valor de cada presente:" << endl;

    for (int i = 0; i < 6; i++) {
        cin >> valor >> quantidade;
        if (quantidade > 1) {
            presentesTroca += (quantidade - 1);
            total += (valor * (quantidade - 1));
        }
    }

    cout << "Numero de presentes a serem trocados: " << presentesTroca << endl;
    
    if (total >= 800) {
        cout << "Voce PODERA adquirir o ar condicionado com as trocas" << endl;
    } else {
        cout << "Voce NAO PODERA adquirir o ar condicionado com as trocas" << endl;
    }

    return 0;
}
