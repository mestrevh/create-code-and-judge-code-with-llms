/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    while (true) {
        cout << "Insira o numero de linhas da matriz:" << endl;
        if (!(cin >> n)) break;
        cout << "Insira o numero de colunas da matriz:" << endl;
        if (!(cin >> m)) break;
        if (n == 0 && m == 0) break;

        long double dn = (long double)n;
        long double dm = (long double)m;
        long double dk = (dn < dm) ? dn : dm;

        long double t = (dn * dm) * (dn * dm + 1.0) / 2.0;
        long double x = (dm + 1.0) * (dk - 1.0) * dk / 2.0 + dk;
        long double a = dm * (dn - 1.0) * dn / 2.0 + dn;
        long double b = dm * dn * (dn + 1.0) / 2.0;
        long double c = dm * (dm + 1.0) / 2.0;
        long double d = (dn - 1.0) * dm * dm + c;

        long double res = (t - x + (a * b) - (c * d)) / (dn * dm);

        cout << "Valor da expressao: " << (double)res << endl;
    }
    return 0;
}