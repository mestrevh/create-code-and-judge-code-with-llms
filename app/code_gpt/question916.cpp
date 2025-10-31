/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int numero;
    while (true) {
        cout << "Digite um numero (negativo para parar o programa): ";
        cin >> numero;
        if (numero < 0) break;
        cout << "Numero: " << numero << endl;
    }
    return 0;
}
