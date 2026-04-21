/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    while (cin >> a >> b >> c) {
        cout << "Digite o valor de Alice:\n";
        cout << "Digite o valor de Beto:\n";
        cout << "Digite o valor de Clara:\n";

        if ((a != "0" && a != "1") || (b != "0" && b != "1") || (c != "0" && c != "1")) {
            cout << "Algum valor digitado e diferente de 0 ou 1.\n";
        } else if (a != b && a != c) {
            cout << "O vencedor e Alice.\n";
        } else if (b != a && b != c) {
            cout << "O vencedor e Beto.\n";
        } else if (c != a && c != b) {
            cout << "O vencedor e Clara.\n";
        } else {
            cout << "Nao houve vencedor.\n";
        }
    }

    return 0;
}