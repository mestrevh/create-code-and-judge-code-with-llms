/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char nacionalidade, sexo;
    int idade;
    double valorIngresso;

    cin >> nacionalidade >> idade >> sexo >> valorIngresso;

    if (idade <= 0 || idade > 120) {
        cout << "idade invalida!" << endl;
        return 0;
    }

    bool podeComprar = false;
    double desconto = 0.0;

    if (nacionalidade == 'B' || nacionalidade == 'A') {
        podeComprar = true;
        if (nacionalidade == 'B') desconto = 0.50;
        if (nacionalidade == 'A') {
            if (idade < 18) desconto = 0.20;
            else if (sexo == 'F') desconto = 0.20;
        }
    } else if (nacionalidade == 'F' || nacionalidade == 'C') {
        if (idade >= 21) {
            podeComprar = true;
            desconto = 0.30;
        }
    } else if (nacionalidade == 'I' || nacionalidade == 'R') {
        podeComprar = true;
        if (idade < 16) desconto = 0.40;
        else desconto = 0.30;
    }

    if (nacionalidade == 'B' && idade >= 18) {
        desconto = 0.50;
    } else if ((nacionalidade == 'A' && sexo == 'M' && idade >= 18) || 
               ((nacionalidade == 'B' || nacionalidade == 'A') && idade < 18)) {
        desconto = max(desconto, 0.20);
    }

    if (!podeComprar) {
        cout << "nao pode comprar" << endl;
    } else {
        double valorFinal = valorIngresso * (1 - desconto);
        cout << fixed << setprecision(2);
        cout << "R$ " << valorFinal << endl;
    }
    return 0;
}
