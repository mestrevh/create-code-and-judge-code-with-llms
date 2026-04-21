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

    double valor_total;
    if (!(cin >> valor_total)) return 0;

    double a_vista_desconto = valor_total * 0.90;
    double valor_parcela = valor_total / 3.0;
    double comissao_vista = a_vista_desconto * 0.05;
    double comissao_prazo = valor_total * 0.05;

    cout << fixed << setprecision(2);
    cout << "A vista com desconto de 10%: " << a_vista_desconto << "\n";
    cout << "Valor da parcela em 3x sem juros: " << valor_parcela << "\n";
    cout << "Comissao do vendedor a vista: " << comissao_vista << "\n";
    cout << "Comissao do vendedor a prazo: " << comissao_prazo << "\n";

    return 0;
}