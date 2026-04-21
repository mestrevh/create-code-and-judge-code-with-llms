/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long estoque[4];
    if (!(cin >> estoque[0] >> estoque[1] >> estoque[2] >> estoque[3])) return 0;

    map<string, int> idx = {
        {"Fenix", 0},
        {"Dragao", 1},
        {"Unicornio", 2},
        {"Testralio", 3}
    };

    long long dinheiroG = 0, dinheiroS = 0, dinheiroN = 0;

    auto addMoney = [&](long long g, long long s, long long n) {
        dinheiroN += n;
        dinheiroS += s;
        dinheiroG += g;

        if (dinheiroN >= 29) {
            long long carryS = dinheiroN / 29;
            dinheiroN %= 29;
            dinheiroS += carryS;
        }
        if (dinheiroS >= 17) {
            long long carryG = dinheiroS / 17;
            dinheiroS %= 17;
            dinheiroG += carryG;
        }
    };

    map<string, array<long long,3>> price = {
        {"Fenix", {5, 16, 22}},
        {"Dragao", {1, 2, 28}},
        {"Unicornio", {2, 10, 12}},
        {"Testralio", {3, 10, 0}}
    };

    string r;
    while (cin >> r) {
        if (r == "FIM") break;
        int i = idx[r];
        if (estoque[i] > 0) {
            estoque[i]--;
            auto p = price[r];
            addMoney(p[0], p[1], p[2]);
        }
    }

    cout << "Fenix " << estoque[0] << "\n";
    cout << "Dragao " << estoque[1] << "\n";
    cout << "Unicornio " << estoque[2] << "\n";
    cout << "Testralio " << estoque[3] << "\n";
    cout << dinheiroG << " " << dinheiroS << " " << dinheiroN << "\n";
    return 0;
}