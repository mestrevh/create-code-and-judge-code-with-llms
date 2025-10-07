/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> mapa(11, string(20, ' '));
    int pos = 10;

    while (true) {
        string direcao;
        int distancia;
        cin >> direcao;

        if (direcao == "x") break;
        cin >> distancia;

        for (int i = 0; i < distancia; i++) {
            if (direcao == "d") {
                pos++;
                if (pos < 20) mapa[10][pos] = '>';
            } else if (direcao == "e") {
                pos--;
                if (pos >= 0) mapa[10][pos] = '<';
            } else if (direcao == "f") {
                mapa[10 - i][pos] = '|';
            }
        }
    }

    for (int i = 0; i < 11; i++) {
        if (i == 10) mapa[i][pos] = 'x';
        cout << mapa[i] << endl;
    }

    return 0;
}
