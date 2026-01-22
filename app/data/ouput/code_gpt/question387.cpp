/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int cartas[5];
    for (int i = 0; i < 5; i++) {
        cin >> cartas[i];
    }

    bool crescente = true, decrescente = true;

    for (int i = 1; i < 5; i++) {
        if (cartas[i] > cartas[i - 1]) {
            decrescente = false;
        } else if (cartas[i] < cartas[i - 1]) {
            crescente = false;
        }
    }

    if (crescente) {
        cout << 'C';
    } else if (decrescente) {
        cout << 'D';
    } else {
        cout << 'N';
    }

    return 0;
}
