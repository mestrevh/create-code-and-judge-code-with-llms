/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ph;
    if (!(cin >> ph)) return 0;

    cout << "Digite o pH da solucao:" << endl;

    if (ph < 0.0 || ph > 14.0) {
        cout << "Valor do pH deve estar entre 0 e 14" << endl;
    } else if (ph < 7.0) {
        cout << "Solucao acida" << endl;
    } else if (ph > 7.0) {
        cout << "Solucao basica" << endl;
    } else {
        cout << "Solucao neutra" << endl;
    }

    return 0;
}