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
    double produto = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matriz[i][j];

    for (int i = 0; i < n; ++i)
        produto *= matriz[i][i];

    cout << produto << endl;
    return 0;
}
