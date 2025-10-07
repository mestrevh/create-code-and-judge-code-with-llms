/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Digite as coordenadas (X, Y) separadas por ENTER:" << endl;
    cin >> x >> y;

    if (x >= 0 && x <= 432 && y >= 0 && y <= 468) {
        cout << "BOLA DENTRO" << endl;
    } else {
        cout << "BOLA FORA" << endl;
    }

    return 0;
}
