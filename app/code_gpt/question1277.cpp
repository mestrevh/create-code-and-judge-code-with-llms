/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int matriz[n][n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matriz[i][j];

    bool triangularSuperior = true;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matriz[i][j] != 0) {
                triangularSuperior = false;
                break;
            }
        }
        if (!triangularSuperior) break;
    }

    cout << (triangularSuperior ? "true" : "false") << endl;
    return 0;
}
