/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Digite o pH da solucao:" << endl;
    double pH;
    if (!(cin >> pH)) return 0;

    if (pH < 0 || pH > 14) {
        cout << "Valor deve estar entre 0 e 14." << endl;
    } else if (pH < 7) {
        cout << "Essa solucao e acida." << endl;
    } else if (pH > 7) {
        cout << "Essa solucao e basica." << endl;
    } else {
        cout << "Essa solucao e neutra." << endl;
    }
    return 0;
}