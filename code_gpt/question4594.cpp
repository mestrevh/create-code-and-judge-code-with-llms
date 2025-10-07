/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

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
    std::string numero;
    float saldo;
    std::cin >> numero >> saldo;
    
    Conta conta = {numero, saldo};

    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::string operacao;
        float valor;
        std::cin >> operacao >> valor;

        if (operacao == "CREDITAR") {
            creditar(&conta, valor);
        } else if (operacao == "DEBITAR") {
            debitar(&conta, valor);
        }
    }

    std::cout << std::fixed << std::setprecision(2) << conta.saldo << std::endl;

    return 0;
}
