/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int verificaPar(int n) {
    return n % 2 == 0 ? 1 : 0;
}

int main() {
    int numero;
    cin >> numero;
    if (verificaPar(numero)) {
        cout << "par" << endl;
    } else {
        cout << "nao par" << endl;
    }
    return 0;
}
