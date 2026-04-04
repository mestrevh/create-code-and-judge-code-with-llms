/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double days, km;
    if (!(cin >> days >> km)) return 0;

    // A diária custa R$ 30,00 e o km rodado custa R$ 0,01.
    // O valor total tem um desconto de 10%.
    double base_cost = (days * 30.0) + (km * 0.01);
    double final_cost = base_cost * 0.90;

    cout << "Digite a quantidade de dias de locacao:" << "\n";
    cout << "Digite a quantidade de km rodados:" << "\n";
    cout << "Valor a pagar pelo aluguel: R$ " << fixed << setprecision(6) << final_cost << endl;

    return 0;
}