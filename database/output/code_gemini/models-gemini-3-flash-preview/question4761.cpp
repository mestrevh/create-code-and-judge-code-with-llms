/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n < 1) {
        cout << "O número informado é menor que 1." << endl;
    } else {
        int fig = n % 4;
        if (fig == 1) {
            cout << "Esquerda superior: vermelho" << endl;
            cout << "Direita superior: amarelo" << endl;
            cout << "Esquerda inferior: azul" << endl;
            cout << "Direita inferior: verde" << endl;
        } else if (fig == 2) {
            cout << "Esquerda superior: azul" << endl;
            cout << "Direita superior: vermelho" << endl;
            cout << "Esquerda inferior: verde" << endl;
            cout << "Direita inferior: amarelo" << endl;
        } else if (fig == 3) {
            cout << "Esquerda superior: verde" << endl;
            cout << "Direita superior: azul" << endl;
            cout << "Esquerda inferior: amarelo" << endl;
            cout << "Direita inferior: vermelho" << endl;
        } else {
            // fig == 0, which corresponds to the 4th figure in the sequence
            cout << "Esquerda superior: amarelo" << endl;
            cout << "Direita superior: verde" << endl;
            cout << "Esquerda inferior: vermelho" << endl;
            cout << "Direita inferior: azul" << endl;
        }
    }

    return 0;
}