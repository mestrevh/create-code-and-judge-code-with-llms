/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Conta {
    string numero;
    float saldo;
};

void creditar(Conta* conta, float x) {
    conta->saldo += x;
}

void debitar(Conta* conta, float x) {
    conta->saldo -= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string numero;
    float saldoAtual;
    if (!(cin >> numero >> saldoAtual)) return 0;

    Conta conta{numero, saldoAtual};

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string op;
        float x;
        cin >> op >> x;
        if (op == "CREDITAR") creditar(&conta, x);
        else if (op == "DEBITAR") debitar(&conta, x);
    }

    cout.setf(ios::fixed);
    cout << setprecision(2) << conta.saldo << "\n";
    return 0;
}