/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Digite o pH da solucao:" << endl;

    double ph;
    if (cin >> ph) {
        if (ph < 0.0 || ph > 14.0) {
            cout << "Valor deve estar entre 0 e 14." << endl;
        } else if (ph < 7.0) {
            cout << "Essa solucao e acida." << endl;
        } else if (ph > 7.0) {
            cout << "Essa solucao e basica." << endl;
        } else {
            cout << "Essa solucao e neutra." << endl;
        }
    }

    return 0;
}