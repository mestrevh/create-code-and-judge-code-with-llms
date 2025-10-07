/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    int matriz[R][C];
    
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> matriz[i][j];
    
    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < R; ++i) {
            cout << matriz[i][j];
            if (i < R - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
