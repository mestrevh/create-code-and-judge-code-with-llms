/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> names = {
        "", "Cachorro-Quente", "X-Salada", "X-Bacon", "X-Tudo", "Refrigerante", "Suco"
    };
    vector<long double> prices = {
        0.0L, 8.0L, 18.0L, 20.0L, 23.75L, 5.0L, 4.5L
    };

    int code;
    if (!(cin >> code)) return 0;

    if (code == 0) {
        cout << "Código inválido";
        return 0;
    }

    if (code < 1 || code >= (int)names.size() || names[code].empty()) {
        cout << "Código inválido";
        return 0;
    }

    long long qty;
    if (!(cin >> qty)) qty = 0;

    cout << "Você escolheu " << names[code] << "\n";
    long double total = prices[code] * (long double)qty;

    ostringstream oss;
    oss.setf(ios::fixed);
    oss << setprecision(2) << (double)total;
    string totalStr = oss.str();

    cout << "Sua conta é de R$" << totalStr << "\n";
    cout << "Código inválido";
    return 0;
}