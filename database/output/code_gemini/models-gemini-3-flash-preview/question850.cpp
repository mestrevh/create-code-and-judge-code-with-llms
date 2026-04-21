/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int codigo;
    if (!(cin >> codigo)) return 0;

    if (codigo == 1) {
        cout << "Nordeste" << endl;
    } else if (codigo == 2) {
        cout << "Norte" << endl;
    } else if (codigo >= 3 && codigo <= 4) {
        cout << "Centro-Oeste" << endl;
    } else if (codigo >= 5 && codigo <= 9) {
        cout << "Sul" << endl;
    } else if (codigo >= 10 && codigo <= 15) {
        cout << "Sudeste" << endl;
    }

    return 0;
}