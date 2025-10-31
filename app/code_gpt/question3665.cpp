/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int linhas, colunas;
    char letra;
    cin >> linhas >> colunas >> letra;
    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            cin >> matriz[i][j];

    int ascii = letra;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (matriz[i][j] == ascii) {
                cout << letra << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
