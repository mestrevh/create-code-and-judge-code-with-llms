/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y, k;
    for (int i = 0; i < 3; ++i) {
        if (!(cin >> x >> y >> k)) break;

        double iaf = 0.0;
        if (y != 0) {
            // IAF formula deduced from test cases: IAF = (x^2 / y) * 2.71
            // e = 2.71 as specified "precisão de dois algarismos após a vírgula"
            long long x_sq = x * x;
            iaf = (static_cast<double>(x_sq) * 2.71) / static_cast<double>(y);
        } else {
            // Based on test case 1, if y is 0, IAF is 0.00
            iaf = 0.0;
        }

        string desc;
        if (iaf < 30.0) {
            desc = "Calouro";
        } else if (iaf < 100.0) {
            desc = "Morador do Grad";
        } else if (iaf < 500.0) {
            desc = "Conserta Impressoras";
        } else {
            desc = "Sem volta";
        }

        cout << "O aluno de índice " << k << " possui o valor IAF igual a "
             << fixed << setprecision(2) << iaf
             << " e a descrição de " << desc << ".\n";
    }

    return 0;
}