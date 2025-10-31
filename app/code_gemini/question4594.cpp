/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

struct Conta {
    std::string numero;
    float saldo;
};

void creditar(Conta *conta, float x) {
    conta->saldo += x;
}

void debitar(Conta *conta, float x) {
    conta->saldo -= x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Conta minhaConta;
    std::cin >> minhaConta.numero >> minhaConta.saldo;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string operacao;
        float valor;
        std::cin >> operacao >> valor;
        if (operacao == "CREDITAR") {
            creditar(&minhaConta, valor);
        } else if (operacao == "DEBITAR") {
            debitar(&minhaConta, valor);
        }
    }

    std::cout << std::fixed << std::setprecision(2) << minhaConta.saldo << std::endl;

    return 0;
}
