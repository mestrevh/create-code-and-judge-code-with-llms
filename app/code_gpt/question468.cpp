/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double original, desconto;
    int cont = 0;

    for (int i = 0; i < 5; i++) {
        cin >> original >> desconto;
        if ((original - desconto) / original >= 0.20) {
            cont++;
        }
    }

    cout << cont << endl;
    return 0;
}
