/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Conta {
    string numero;
    float saldo;
};

void creditar(Conta *conta, float x) {
    conta->saldo += x;
}

void debitar(Conta *conta, float x) {
    conta->saldo -= x;
}

int main() {
    Conta conta;
    cin >> conta.numero >> conta.saldo;

    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        string operacao;
        float valor;
        cin >> operacao >> valor;
        if (operacao == "CREDITAR") {
            creditar(&conta, valor);
        } else if (operacao == "DEBITAR") {
            debitar(&conta, valor);
        }
    }

    cout << fixed << setprecision(2) << conta.saldo << endl;

    return 0;
}
