/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string nome;
    double salarioFixo, totalVendas;

    if (!(cin >> nome >> salarioFixo >> totalVendas)) return 0;

    double totalReceber = salarioFixo + (totalVendas * 0.15);

    cout << "TOTAL = R$ " << fixed << setprecision(2) << totalReceber << endl;

    return 0;
}