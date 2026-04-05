/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    for (int tc = 0; tc < N; tc++) {
        int total = 0, coelhos = 0, ratos = 0, sapos = 0;

        while (true) {
            int q;
            char tipo;
            if (!(cin >> q >> tipo)) break;
            total += q;
            if (tipo == 'C') coelhos += q;
            else if (tipo == 'R') ratos += q;
            else if (tipo == 'S') sapos += q;
        }

        cout << "Total: " << total << " cobaias\n";
        cout << "Total de coelhos: " << coelhos << "\n";
        cout << "Total de ratos: " << ratos << "\n";
        cout << "Total de sapos: " << sapos << "\n";

        auto printPerc = [&](int val) {
            double p = total ? (100.0 * val / total) : 0.0;
            cout << "Percentual de " ;
            if (&val == &coelhos) cout << "coelhos: ";
            else if (&val == &ratos) cout << "ratos: ";
            else cout << "sapos: ";
            cout << fixed << setprecision(2) << p << " %\n";
        };

        double pC = total ? (100.0 * coelhos / total) : 0.0;
        double pR = total ? (100.0 * ratos / total) : 0.0;
        double pS = total ? (100.0 * sapos / total) : 0.0;

        cout << "Percentual de coelhos: " << fixed << setprecision(2) << pC << " %\n";
        cout << "Percentual de ratos: " << fixed << setprecision(2) << pR << " %\n";
        cout << "Percentual de sapos: " << fixed << setprecision(2) << pS << " %\n";

        if (tc != N - 1) cout << "";
    }

    return 0;
}