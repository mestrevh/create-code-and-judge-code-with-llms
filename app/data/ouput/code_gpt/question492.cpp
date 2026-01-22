/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int totalCapsulas = 0;
    int totalXicaras = 0;

    for (int i = 0; i < 7; ++i) {
        int quantidade;
        string tamanho;
        cin >> quantidade >> tamanho;

        if (tamanho == "P" || tamanho == "p") {
            totalCapsulas += quantidade * 10;
        } else if (tamanho == "G" || tamanho == "g") {
            totalCapsulas += quantidade * 16;
        }
    }

    totalXicaras = totalCapsulas * 2;
    cout << totalCapsulas << endl;
    cout << totalXicaras << endl;

    return 0;
}
