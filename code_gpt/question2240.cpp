/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int C, L, x, y;
    string tipo;
    cin >> C >> L >> tipo >> x >> y;

    bool rebatida = false;

    if (tipo == "Saque") {
        if (x > C / 2 && y > 0 && y < L) {
            rebatida = true;
        }
    } else {
        if (x > C / 2 && y > L / 4 && y < 3 * L / 4) {
            rebatida = true;
        }
    }

    if (rebatida) {
        cout << "A bola foi rebatida" << endl;
    } else {
        cout << "A bola foi para fora" << endl;
    }

    return 0;
}
