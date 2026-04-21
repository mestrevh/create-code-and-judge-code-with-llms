/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxCriancas;
    if (!(cin >> maxCriancas)) return 0;

    bool first = true;
    while (true) {
        int adultos;
        cin >> adultos;
        if (!cin) break;
        if (adultos < 0) break;

        long long criancasResidentes, criancasConvidadas;
        cin >> criancasResidentes;
        cin >> criancasConvidadas;

        long long criancasTotais = criancasResidentes + criancasConvidadas;

        if (!first) cout << "";
        first = false;

        if (criancasConvidadas > 0) {
            cout << "Acesso permitido devido a presenca de convidado(s).\n";
        } else {
            if (criancasTotais <= maxCriancas) {
                cout << "Acesso permitido!\n";
            } else {
                cout << "Capacidade maxima de criancas atingida/excedida.\n";
                cout << "Tem " << (criancasTotais - maxCriancas) << " crianca(s) a mais que as " << maxCriancas << " permitidas.\n";
            }
        }

        cout << "Adultos na piscina: " << adultos << "\n";
        cout << "Criancas na piscina: " << criancasTotais << "\n";
        cout << "***\n";
    }

    return 0;
}