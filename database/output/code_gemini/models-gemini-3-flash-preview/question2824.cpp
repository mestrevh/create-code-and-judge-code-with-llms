/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_pessoas;
    int cidade;
    int qtd_quartos;

    cout << "Digite a quantidade de pessoas:" << endl;
    if (!(cin >> qtd_pessoas)) return 0;
    
    cout << "Selecione a cidade escolhida: (1 - Pipa e 2 - Fortaleza)" << endl;
    if (!(cin >> cidade)) return 0;
    
    cout << "Digite a quantidade de quartos:" << endl;
    if (!(cin >> qtd_quartos)) return 0;

    double custo_casa = 0.0;
    double custo_atracao = 0.0;

    if (cidade == 1) { // Pipa
        if (qtd_quartos == 2) {
            custo_casa = 600.0;
        } else if (qtd_quartos == 3) {
            custo_casa = 900.0;
        }
        custo_atracao = 75.0 * qtd_pessoas;
    } else if (cidade == 2) { // Fortaleza
        if (qtd_quartos == 3) {
            custo_casa = 950.0;
        } else if (qtd_quartos == 4) {
            custo_casa = 1120.0;
        }
        custo_atracao = 60.0 * qtd_pessoas;
    }

    double valor_total = custo_casa + custo_atracao;
    double valor_por_pessoa = (qtd_pessoas > 0) ? (valor_total / (double)qtd_pessoas) : 0.0;

    cout << fixed << setprecision(2);
    cout << "Valor total da viagem: R$ " << valor_total << endl;
    cout << "Valor por pessoa: R$ " << valor_por_pessoa << endl;

    return 0;
}