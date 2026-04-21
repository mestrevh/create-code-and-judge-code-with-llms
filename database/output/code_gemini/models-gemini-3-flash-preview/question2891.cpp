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

    double compra, venda;
    double total_compra = 0, total_venda = 0;
    int c10 = 0, c10_20 = 0, c20 = 0;

    for (int i = 0; i < 10; ++i) {
        cout << "Digite o preco de compra:" << endl;
        if (!(cin >> compra)) break;
        cout << "Digite o preco de venda:" << endl;
        if (!(cin >> venda)) break;

        total_compra += compra;
        total_venda += venda;

        double profit = ((venda - compra) / compra) * 100.0;

        if (profit <= 10.0) {
            c10++;
        } else if (profit < 20.0) {
            c10_20++;
        } else {
            c20++;
        }
    }

    cout << "Mercadorias com lucro menor ou igual a 10%: " << c10 << endl;
    cout << "Mercadorias com lucro maior que 10% e menor que 20%: " << c10_20 << endl;
    cout << "Mercadorias com lucro maior ou igual a 20%: " << c20 << endl;
    cout << "Total de compra das mercadorias: R$ " << total_compra << endl;
    cout << "Total de venda das mercadorias: R$ " << total_venda << endl;

    if (total_compra > 0) {
        double total_profit_percent = ((total_venda - total_compra) / total_compra) * 100.0;
        cout << fixed << setprecision(4) << "Percentual de lucro total: " << total_profit_percent << " %" << endl;
    } else {
        cout << fixed << setprecision(4) << "Percentual de lucro total: 0.0000 %" << endl;
    }

    return 0;
}