/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    while (true) {
        cout << "Insira o numero de linhas da matriz:" << endl;
        cin >> n;
        cout << "Insira o numero de colunas da matriz:" << endl;
        cin >> m;

        if (n == 0 && m == 0) break;

        int t = n * m * (n * m + 1) / 2;
        int x = 0, a = 0, b = 0, c = 0, d = 0;

        for (int i = 0; i < n; ++i) {
            if (i < m) x += (i * m + (i + 1));
            if (i == 0) {
                a += (i * m + 1);
                for (int j = 1; j < m; ++j) a += (i * m + (j + 1));
            }
            if (i == n - 1) {
                d += (i * m + 1);
                for (int j = 1; j < m; ++j) d += (i * m + (j + 1));
            }
            b += (i * m + m);
        }

        c = a;
        double resultado = (t - x + (a * b) - (c * d)) / static_cast<double>(n * m);

        cout << fixed << setprecision(2);
        cout << "Valor da expressao: " << resultado << endl;
    }
    return 0;
}
