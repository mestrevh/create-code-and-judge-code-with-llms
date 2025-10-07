/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int acertosPortugues, acertosMatematica;
    double notaRedacao;
    int aprovados = 0;

    while (true) {
        cin >> acertosPortugues;
        if (acertosPortugues < 0) break;
        cin >> acertosMatematica >> notaRedacao;

        if (acertosPortugues >= 40 && acertosMatematica >= 21 && notaRedacao >= 7.0) {
            aprovados++;
        }
    }

    cout << aprovados << endl;
    return 0;
}
