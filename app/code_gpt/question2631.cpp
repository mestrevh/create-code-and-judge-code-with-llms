/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cout << "Digite o valor de Alice:\n";
    cin >> A;
    cout << "Digite o valor de Beto:\n";
    cin >> B;
    cout << "Digite o valor de Clara:\n";
    cin >> C;

    if ((A != 0 && A != 1) || (B != 0 && B != 1) || (C != 0 && C != 1)) {
        cout << "Algum valor digitado e diferente de 0 ou 1.\n";
    } else if (A == B && B == C) {
        cout << "Nao houve vencedor.\n";
    } else if (A != B && A != C) {
        cout << "O vencedor e Alice.\n";
    } else if (B != A && B != C) {
        cout << "O vencedor e Beto.\n";
    } else {
        cout << "O vencedor e Clara.\n";
    }
    return 0;
}
