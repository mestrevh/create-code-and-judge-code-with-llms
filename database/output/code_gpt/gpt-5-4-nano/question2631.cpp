/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cout << "Digite o valor de Alice:\n";
    if (!(cin >> A)) return 0;
    cout << "Digite o valor de Beto:\n";
    if (!(cin >> B)) return 0;
    cout << "Digite o valor de Clara:\n";
    if (!(cin >> C)) return 0;

    if ((A != 0 && A != 1) || (B != 0 && B != 1) || (C != 0 && C != 1)) {
        cout << "Algum valor digitado e diferente de 0 ou 1.";
        return 0;
    }

    int x[3] = {A, B, C};
    if (A != B && A != C) {
        cout << "O vencedor e Alice.";
    } else if (B != A && B != C) {
        cout << "O vencedor e Beto.";
    } else if (C != A && C != B) {
        cout << "O vencedor e Clara.";
    } else {
        cout << "Nao houve vencedor.";
    }

    return 0;
}