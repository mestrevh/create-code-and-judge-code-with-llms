/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float ph;
    cout << "Digite o pH da solucao:" << endl;
    cin >> ph;

    if (ph < 0 || ph > 14) {
        cout << "Valor do pH deve estar entre 0 e 14" << endl;
    } else if (ph < 7) {
        cout << "Solucao acida" << endl;
    } else if (ph > 7) {
        cout << "Solucao basica" << endl;
    } else {
        cout << "Solucao neutra" << endl;
    }
    return 0;
}
