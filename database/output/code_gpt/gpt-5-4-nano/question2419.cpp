/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double O;
    if (!(cin >> O)) return 0;

    struct Cel {
        string s;
        double p, n;
    };

    vector<Cel> c(3);
    for (int i = 0; i < 3; i++) {
        cin >> c[i].s >> c[i].p >> c[i].n;
    }

    int best = -1;
    double bestCB = -1.0;

    auto canBuy = [&](const Cel& x) { return x.p <= O + 1e-9; };

    for (int i = 0; i < 3; i++) {
        if (!canBuy(c[i])) continue;
        if (c[i].p == 0) continue;
        double cb = c[i].n / c[i].p;
        if (best == -1) {
            best = i;
            bestCB = cb;
            continue;
        }
        const Cel& cur = c[i];
        const Cel& b = c[best];
        if (cb > bestCB + 1e-12) {
            best = i;
            bestCB = cb;
        } else if (fabs(cb - bestCB) <= 1e-12) {
            if (cur.p < b.p - 1e-12) {
                best = i;
            } else if (fabs(cur.p - b.p) <= 1e-12) {
                if (i < best) best = i;
            }
        }
    }

    if (best == -1) {
        cout << "O meu celular nem esta tao ruim assim";
    } else {
        cout << "Comprarei o celular " << c[best].s;
    }

    return 0;
}