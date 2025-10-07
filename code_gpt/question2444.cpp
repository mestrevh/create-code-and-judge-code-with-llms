/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int vida, estamina;
    string arma;
    
    cin >> vida >> estamina >> arma;
    
    if (arma != "pedra" && arma != "graveto") {
        cout << "Tarzan nao consegue lutar sem armas... Ele foi capturado" << endl;
        return 0;
    }
    
    int danoVida = (arma == "pedra") ? 15 : 10;
    int danoEstamina = (arma == "pedra") ? 13 : 8;
    
    while (vida > 0 && estamina > 0) {
        vida -= danoVida;
        estamina -= danoEstamina;
    }
    
    if (vida <= 0) {
        cout << "Tarzan venceu o invasor e o expulsou de sua floresta" << endl;
    } else {
        cout << "Tarzan nao foi capaz de derrotar o invasor... Ele foi capturado" << endl;
    }
    
    return 0;
}
