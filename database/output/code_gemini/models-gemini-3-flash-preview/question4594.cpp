/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Conta {
    string numero;
    float saldo;
};

void creditar(Conta *conta, float x) {
    if (conta) {
        conta->saldo += x;
    }
}

void debitar(Conta *conta, float x) {
    if (conta) {
        conta->saldo -= x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Conta conta;
    if (!(cin >> conta.numero >> conta.saldo)) {
        return 0;
    }

    int n;
    if (!(cin >> n)) {
        cout << fixed << setprecision(2) << conta.saldo << endl;
        return 0;
    }

    string operacao;
    float valor;
    for (int i = 0; i < n; ++i) {
        if (!(cin >> operacao >> valor)) {
            break;
        }
        if (operacao == "CREDITAR") {
            creditar(&conta, valor);
        } else if (operacao == "DEBITAR") {
            debitar(&conta, valor);
        }
    }

    cout << fixed << setprecision(2) << conta.saldo << endl;

    return 0;
}