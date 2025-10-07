/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int veículos;
    cin >> veículos;
    double vagas_totais = 42.0;
    double preço_por_carro = 1.75;
    double disponíveis = vagas_totais - veículos;
    double faturamento_possível = disponíveis * preço_por_carro;
    
    cout << fixed << setprecision(2) << faturamento_possível << endl;
    return 0;
}
