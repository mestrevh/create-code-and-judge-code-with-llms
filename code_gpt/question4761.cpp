/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void exibirFigura(int n) {
    const string cores[4][4] = {
        {"vermelho", "amarelo", "azul", "verde"},
        {"verde", "azul", "amarelo", "vermelho"},
        {"azul", "verde", "vermelho", "amarelo"},
        {"amarelo", "vermelho", "verde", "azul"}
    };
    n = (n - 1) % 4;
    cout << "Esquerda superior: " << cores[n][0] << endl;
    cout << "Direita superior: " << cores[n][1] << endl;
    cout << "Esquerda inferior: " << cores[n][2] << endl;
    cout << "Direita inferior: " << cores[n][3] << endl;
}

int main() {
    int n;
    cin >> n;
    if (n < 1) {
        cout << "O número informado é menor que 1." << endl;
    } else {
        exibirFigura(n);
    }
    return 0;
}
