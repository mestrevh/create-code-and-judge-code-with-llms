/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string est, id;
    if (!(cin >> est)) return 0;
    if (!(cin >> id)) return 0;

    cout << "Cliente e estudante? (s ou n)\n";
    cout << "Cliente e idoso? (s ou n)\n";

    auto isS = [](const string& x) {
        if (x.empty()) return false;
        char c = (char)tolower((unsigned char)x[0]);
        return c == 's';
    };
    auto isN = [](const string& x) {
        if (x.empty()) return false;
        char c = (char)tolower((unsigned char)x[0]);
        return c == 'n';
    };

    bool estOk = isS(est) || isN(est);
    bool idOk = isS(id) || isN(id);

    if (!estOk || !idOk) {
        cout << "Entrada deve ser apenas pelas letras s ou n.";
        return 0;
    }

    bool meia = isS(est) || isS(id);
    if (meia) cout << "Meia-entrada. Valor a ser pago: R$10,00.";
    else cout << "Entrada completa. Valor a ser pago: R$20,00.";

    return 0;
}