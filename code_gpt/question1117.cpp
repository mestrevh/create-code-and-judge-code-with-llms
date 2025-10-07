/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char continuar;
    int ano, maiorAno = 0, cont = 0;
    float velocidade, maiorVelocidade = 0.0, somaVelocidades = 0.0;

    while (true) {
        cin >> continuar;
        if (continuar == 'n' || continuar == 'N') break;
        cin >> ano >> velocidade;

        if (velocidade > maiorVelocidade) maiorVelocidade = velocidade;
        if (ano > maiorAno) maiorAno = ano;

        somaVelocidades += velocidade;
        cont++;
    }

    if (cont == 0) {
        cout << "zero" << endl;
    } else {
        cout << fixed << setprecision(2) << maiorVelocidade << endl;
        cout << maiorAno << endl;
        cout << fixed << setprecision(2) << (somaVelocidades / cont) << endl;
    }

    return 0;
}
