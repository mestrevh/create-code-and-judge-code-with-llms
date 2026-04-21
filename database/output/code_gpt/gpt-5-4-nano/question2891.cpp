/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 10;
    vector<double> buy(N), sell(N);

    for (int i = 0; i < N; i++) {
        cout << "Digite o preco de compra:";
        cin >> buy[i];
        cout << "Digite o preco de venda:";
        cin >> sell[i];
    }

    int le10 = 0, gt10lt20 = 0, ge20 = 0;
    for (int i = 0; i < N; i++) {
        double pct = (sell[i] - buy[i]) / buy[i] * 100.0;
        if (pct <= 10.0 + 1e-12) le10++;
        if (pct > 10.0 + 1e-12 && pct < 20.0 - 1e-12) gt10lt20++;
        if (pct >= 20.0 - 1e-12) ge20++;
    }

    double totalBuy = accumulate(buy.begin(), buy.end(), 0.0);
    double totalSell = accumulate(sell.begin(), sell.end(), 0.0);

    double profitPct = (totalSell - totalBuy) / totalBuy * 100.0;

    cout << "Mercadorias com lucro menor ou igual a 10%: " << le10 << "\n";
    cout << "Mercadorias com lucro maior que 10% e menor que 20%: " << gt10lt20 << "\n";
    cout << "Mercadorias com lucro maior ou igual a 20%: " << ge20 << "\n";
    cout << "Total de compra das mercadorias: R$ " << fixed << setprecision(1) << totalBuy << "\n";
    cout << "Total de venda das mercadorias: R$ " << fixed << setprecision(1) << totalSell << "\n";
    cout << "Percentual de lucro total: " << fixed << setprecision(4) << profitPct << " %";

    return 0;
}