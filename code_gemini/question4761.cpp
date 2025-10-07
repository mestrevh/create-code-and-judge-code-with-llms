/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        cout << "O número informado é menor que 1." << endl;
        return 0;
    }

    n %= 4;
    if (n == 0) n = 4;

    if (n == 1) {
        cout << "Esquerda superior: vermelho" << endl;
        cout << "Direita superior: amarelo" << endl;
        cout << "Esquerda inferior: azul" << endl;
        cout << "Direita inferior: verde" << endl;
    } else if (n == 2) {
        cout << "Esquerda superior: amarelo" << endl;
        cout << "Direita superior: vermelho" << endl;
        cout << "Esquerda inferior: verde" << endl;
        cout << "Direita inferior: azul" << endl;
    } else if (n == 3) {
        cout << "Esquerda superior: verde" << endl;
        cout << "Direita superior: azul" << endl;
        cout << "Esquerda inferior: amarelo" << endl;
        cout << "Direita inferior: vermelho" << endl;
    } else if (n == 4) {
        cout << "Esquerda superior: azul" << endl;
        cout << "Direita superior: vermelho" << endl;
        cout << "Esquerda inferior: verde" << endl;
        cout << "Direita inferior: amarelo" << endl;
    }

    return 0;
}
