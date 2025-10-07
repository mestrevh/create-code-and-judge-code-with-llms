/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int menorQueZero(int num) {
    return (num < 0) ? 1 : 0;
}

int main() {
    int numero;
    cin >> numero;
    
    if (menorQueZero(numero)) {
        cout << "menor" << endl;
    } else {
        cout << "nao menor" << endl;
    }
    
    return 0;
}
