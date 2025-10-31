/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int matriz1[6][6], matriz2[6][6], resultado[6][6];
    
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> matriz1[i][j];

    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> matriz2[i][j];

    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << resultado[i][j];
            if (j < 5) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
