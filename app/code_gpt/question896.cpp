/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float nota;
    while (true) {
        cout << "Informe uma nota entre 0 e 10: ";
        cin >> nota;
        if (nota >= 0 && nota <= 10) {
            cout << "Siga" << endl;
            break;
        } else {
            cout << "Valor invalido" << endl;
        }
    }
    return 0;
}
