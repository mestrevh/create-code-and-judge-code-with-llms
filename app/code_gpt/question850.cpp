/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int codigo;
    cin >> codigo;

    if (codigo == 1) {
        cout << "Nordeste" << endl;
    } else if (codigo == 2) {
        cout << "Norte" << endl;
    } else if (codigo == 3 || codigo == 4) {
        cout << "Centro-Oeste" << endl;
    } else if (codigo >= 5 && codigo <= 9) {
        cout << "Sul" << endl;
    } else if (codigo >= 10 && codigo <= 15) {
        cout << "Sudeste" << endl;
    } else {
        cout << "Código inválido" << endl;
    }

    return 0;
}
