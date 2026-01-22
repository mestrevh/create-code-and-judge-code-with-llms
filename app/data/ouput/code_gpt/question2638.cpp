/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double pH;
    cout << "Digite o pH da solucao:" << endl;
    cin >> pH;

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
