/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int base, expoente;
    while (true) {
        cout << "Informe a base:" << endl;
        cin >> base;
        cout << "Informe o expoente:" << endl;
        cin >> expoente;

        int resultado = 1;
        for (int i = 0; i < expoente; i++) {
            resultado *= base;
        }

        cout << "Resultado: " << resultado << endl;
    }
    return 0;
}
