/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string codigo;
    cin >> codigo;

    if (codigo.length() == 10) {
        char tipo = codigo[6];
        if (tipo == 'b') {
            cout << "Bulbassauro" << endl;
        } else if (tipo == 'c') {
            cout << "Charmander" << endl;
        } else if (tipo == 's') {
            cout << "Squirtle" << endl;
        } else {
            cout << "Codigo Invalido" << endl;
        }
    } else {
        cout << "Codigo Invalido" << endl;
    }

    return 0;
}
