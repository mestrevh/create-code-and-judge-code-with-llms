/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int k;
    while (cin >> k && k != 0) {
        int matriz[4][4];
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> matriz[i][j];
        
        for (int i = 0; i < 4; ++i)
            matriz[i][i] *= k;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                cout << matriz[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
