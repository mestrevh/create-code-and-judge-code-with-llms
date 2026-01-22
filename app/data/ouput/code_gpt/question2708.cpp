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

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (matriz[i][j] < 0)
                cout << matriz[i][j] * 2 << " ";
            else
                cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
