/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float largura, comprimento, altura;
    cout << "Digite a largura da bagagem:\n";
    cin >> largura;
    cout << "Digite o comprimento da bagagem:\n";
    cin >> comprimento;
    cout << "Digite a altura da bagagem:\n";
    cin >> altura;

    if (largura <= 45 && comprimento <= 56 && altura <= 25) {
        cout << "BAGAGEM PERMITIDA\n";
    } else {
        cout << "BAGAGEM PROIBIDA\n";
    }
    return 0;
}
