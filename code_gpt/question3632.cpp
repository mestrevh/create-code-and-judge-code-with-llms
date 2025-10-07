/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double indice;
    cin >> indice;

    if (indice > 0.25 && indice <= 0.3) {
        cout << "Grupo 1" << endl;
    } else if (indice > 0.3 && indice <= 0.4) {
        cout << "Grupo 1" << endl;
        cout << "Grupo 2" << endl;
    } else if (indice > 0.4) {
        cout << "Grupo 1" << endl;
        cout << "Grupo 2" << endl;
        cout << "Grupo 3" << endl;
    }

    return 0;
}
