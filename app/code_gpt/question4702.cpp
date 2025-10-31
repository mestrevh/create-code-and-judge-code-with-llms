/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

string par_ou_impar(int numero) {
    return (numero % 2 == 0) ? "Par" : "Ímpar";
}

int main() {
    int numero;
    cin >> numero;
    cout << par_ou_impar(numero) << endl;
    return 0;
}
