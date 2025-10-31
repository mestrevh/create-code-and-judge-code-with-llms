/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int fatorial(int n) {
    if (n <= 0) return 1;
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;
    cout << "Digite um numero inteiro:\n";
    cin >> numero;
    cout << "Fatorial: " << fatorial(numero) << endl;
    return 0;
}
