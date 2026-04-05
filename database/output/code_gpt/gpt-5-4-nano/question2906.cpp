/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H, A;
    if (!(cin >> H)) return 0;
    if (!(cin >> A)) return 0;

    long long distanciaTitan = (50 + H - 1) / H - 1;
    long long alturaTit = 50 - H * max(0LL, distanciaTitan);
    alturaTit = 50 - H * distanciaTitan;
    long long alturaSoldado = A * ((distanciaTitan < 0) ? 0 : (distanciaTitan + 1));

    long long kTitan = (50 + H - 1) / H;
    long long heightSoldier = (kTitan - 1) * A;

    if (heightSoldier >= 50) {
        cout << "Capturamos ele, comandante!\n";
        cout << "Altura alcancada pelo tita: " << (kTitan * H) << "\n";
        cout << "Altura alcancada pelo soldado: " << heightSoldier << "\n";
    } else {
        cout << "Comandante, a operacao falhou!\n";
        cout << "altura alcancada pelo soldado: " << heightSoldier << "\n";
    }
    return 0;
}