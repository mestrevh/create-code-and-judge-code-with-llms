/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> meses = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    vector<string> dias = {"Sábado", "Domingo"};
    double chance[12][8];
    int melhorDia = -1, melhorMes = -1, melhorTipo = -1;
    double menorChance = 1.0;

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 8; j++)
            cin >> chance[i][j];

    for (int mes = 0; mes < 12; mes++) {
        for (int tipo = 0; tipo < 8; tipo += 2) {
            double chuva = chance[mes][tipo];
            if (chuva <= 0.5) {
                if (chuva < menorChance) {
                    menorChance = chuva;
                    melhorDia = tipo / 2; // 0 a 3
                    melhorMes = mes; // 0 a 11
                    melhorTipo = tipo % 2; // 0 para Sábado, 1 para Domingo
                }
            }
        }
    }

    if (melhorDia == -1) {
        cout << "Proximo ano eu tento denovo..." << endl;
    } else {
        cout << "O melhor dia e no " 
             << (melhorDia == 0 ? "Primeiro" : (melhorDia == 1 ? "Segundo" : (melhorDia == 2 ? "Terceiro" : "Quarto")))
             << " " << dias[melhorTipo] << " de " << meses[melhorMes] << endl;
    }

    return 0;
}
