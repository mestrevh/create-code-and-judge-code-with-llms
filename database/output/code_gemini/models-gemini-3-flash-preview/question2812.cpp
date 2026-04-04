/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double largura, comprimento, altura;

    cout << "Digite a largura da bagagem:\n";
    if (!(cin >> largura)) return 0;

    cout << "Digite o comprimento da bagagem:\n";
    if (!(cin >> comprimento)) return 0;

    cout << "Digite a altura da bagagem:\n";
    if (!(cin >> altura)) return 0;

    if (largura <= 45.0 && comprimento <= 56.0 && altura <= 25.0) {
        cout << "BAGAGEM PERMITIDA" << endl;
    } else {
        cout << "BAGAGEM PROIBIDA" << endl;
    }

    return 0;
}