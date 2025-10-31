/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    double largura, comprimento, altura;
    cin >> largura >> comprimento >> altura;

    if (largura <= 45 && comprimento <= 56 && altura <= 25) {
        cout << "PERMITIDA" << endl;
    } else {
        cout << "PROIBIDA" << endl;
    }

    return 0;
}
