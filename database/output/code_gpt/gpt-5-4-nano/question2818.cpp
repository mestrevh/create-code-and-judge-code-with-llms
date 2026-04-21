/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double pH;
    cout << "Digite o pH da solucao: ";
    if (!(cin >> pH)) return 0;

    if (pH < 0.0 || pH > 14.0) {
        cout << "Valor do pH deve estar entre 0 e 14";
    } else if (pH < 7.0) {
        cout << "Solucao acida";
    } else if (pH > 7.0) {
        cout << "Solucao basica";
    } else {
        cout << "Solucao neutra";
    }
    return 0;
}