/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    int matriz[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matriz[i][j];
    
    double traco = 0;
    cout << "tr(A) = ";
    for (int i = 0; i < n; ++i) {
        traco += matriz[i][i];
        cout << "(" << fixed << setprecision(2) << matriz[i][i] << ")";
        if (i < n - 1) cout << " + ";
    }
    cout << " = " << fixed << setprecision(2) << traco << endl;
    return 0;
}
