/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long votos83 = 0, votos93 = 0, votosBranco = 0, votosNulo = 0;
    long long v;

    while (cin >> v) {
        if (v == -1) break;
        if (v == 83) votos83++;
        else if (v == 93) votos93++;
        else if (v == 0) votosBranco++;
        else votosNulo++;
    }

    long long validos = votos83 + votos93;

    int vencedor = (votos83 > votos93) ? 83 : 93;
    double a = validos == 0 ? 0.0 : (100.0 * votos83 / validos);
    double b = validos == 0 ? 0.0 : (100.0 * votos93 / validos);

    cout << votos83 << "\n" << votos93 << "\n" << votosBranco << "\n" << votosNulo << "\n" << vencedor << "\n";
    cout.setf(ios::fixed);
    cout << setprecision(2) << a << "\n" << setprecision(2) << b << "\n";

    return 0;
}