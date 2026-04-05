/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prod[12][2];
    for (int i = 0; i < 12; ++i) {
        if (!(cin >> prod[i][0] >> prod[i][1])) break;
    }

    double financial[2][2];
    for (int i = 0; i < 2; ++i) {
        if (!(cin >> financial[i][0] >> financial[i][1])) break;
    }

    cout << fixed << setprecision(2);

    for (int m = 0; m < 2; ++m) {
        for (int i = 0; i < 12; ++i) {
            cout << "Motor[" << m << "], Mes[" << i + 1 << "], custo=[" 
                 << (double)prod[i][m] * financial[m][0] << "], lucro=[" 
                 << (double)prod[i][m] * financial[m][1] << "]\n";
        }
    }

    for (int m = 0; m < 2; ++m) {
        long long total_prod = 0;
        for (int i = 0; i < 12; ++i) {
            total_prod += prod[i][m];
        }
        cout << "Motor[" << m << "], anual, custo=[" 
             << (double)total_prod * financial[m][0] << "], lucro=[" 
             << (double)total_prod * financial[m][1] << "]\n";
    }

    return 0;
}