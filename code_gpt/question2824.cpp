/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int pessoas, cidade, quartos;
    double custo_casa, custo_passeio, valor_total, valor_por_pessoa;

    cout << "Digite a quantidade de pessoas:\n";
    cin >> pessoas;
    cout << "Selecione a cidade escolhida: (1 - Pipa e 2 - Fortaleza)\n";
    cin >> cidade;
    cout << "Digite a quantidade de quartos:\n";
    cin >> quartos;

    if (cidade == 1) {
        if (quartos == 2) {
            custo_casa = 600;
        } else {
            custo_casa = 900;
        }
        custo_passeio = 75 * pessoas;
    } else {
        if (quartos == 3) {
            custo_casa = 950;
        } else {
            custo_casa = 1120;
        }
        custo_passeio = 60 * pessoas;
    }

    valor_total = custo_casa + custo_passeio;
    valor_por_pessoa = valor_total / pessoas;

    cout << fixed << setprecision(2);
    cout << "Valor total da viagem: R$ " << valor_total << "\n";
    cout << "Valor por pessoa: R$ " << valor_por_pessoa << "\n";

    return 0;
}
