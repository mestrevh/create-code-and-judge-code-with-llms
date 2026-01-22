/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    char bairro;
    double renda, consumo;
    cin >> bairro >> renda >> consumo;

    if (renda < 0 || consumo < 0) {
        cout << "Renda e consumo nao podem ser negativos." << endl;
        return 0;
    }

    double desconto = 0.0, valorFinal;

    if (bairro == 'S') {
        if (renda <= 1000) desconto = 0.10;
        else if (renda <= 2000) desconto = 0.05;
    } else if (bairro == 'I') {
        if (renda <= 3000) desconto = 0.08;
        else if (renda <= 4000) desconto = 0.03;
    } else if (bairro == 'T') {
        if (renda <= 15000) desconto = 0.12;
    } else {
        cout << "Bairro invalido." << endl;
        return 0;
    }

    valorFinal = consumo * (1 - desconto);
    cout << static_cast<int>(valorFinal) << endl;

    return 0;
}
