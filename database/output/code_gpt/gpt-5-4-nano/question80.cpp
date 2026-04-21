/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a0[12], a1[12];
    for (int i = 0; i < 12; i++) {
        if (!(cin >> a0[i] >> a1[i])) return 0;
    }

    double cost[2], profit[2];
    for (int k = 0; k < 2; k++) {
        if (!(cin >> cost[k] >> profit[k])) return 0;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    double totalCost[2] = {0.0, 0.0};
    double totalProfit[2] = {0.0, 0.0};

    for (int m = 0; m < 2; m++) {
        for (int i = 0; i < 12; i++) {
            double c = (double)(m == 0 ? a0[i] : a1[i]) * cost[m];
            double p = (double)(m == 0 ? a0[i] : a1[i]) * profit[m];
            totalCost[m] += c;
            totalProfit[m] += p;
            cout << "Motor[" << m << "], Mes[" << (i + 1) << "], custo=[" << c << "], lucro=[" << p << "]\n";
        }
    }

    for (int m = 0; m < 2; m++) {
        cout << "Motor[" << m << "], anual, custo=[" << totalCost[m] << "], lucro=[" << totalProfit[m] << "]\n";
    }

    return 0;
}