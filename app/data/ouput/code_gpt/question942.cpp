/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int dias;
    cin >> dias;
    vector<vector<double>> tabela(5, vector<double>(7, 0.0));
    
    for (int i = 0; i < (dias + 6) / 7; ++i) {
        for (int j = 0; j < 7 && (i * 7 + j) < dias; ++j) {
            cin >> tabela[i][j];
        }
    }

    int diasFuncionou = 0;
    double totalVendas = 0.0, maiorFaturamento = 0.0, menorFaturamento = 1e9;
    vector<int> diasMaior, diasMenor;

    for (int i = 0; i < dias; ++i) {
        double valor = tabela[i / 7][i % 7];
        if (valor > 0) {
            diasFuncionou++;
            totalVendas += valor;
            if (valor > maiorFaturamento) {
                maiorFaturamento = valor;
                diasMaior = {i + 1};
            } else if (valor == maiorFaturamento) {
                diasMaior.push_back(i + 1);
            }
            if (valor < menorFaturamento) {
                menorFaturamento = valor;
                diasMenor = {i + 1};
            } else if (valor == menorFaturamento) {
                diasMenor.push_back(i + 1);
            }
        }
    }

    double mediaMensal = totalVendas / dias;
    double mediaDiaria = diasFuncionou > 0 ? totalVendas / diasFuncionou : 0.0;

    cout << diasFuncionou << endl;
    cout << fixed << setprecision(2) << mediaMensal << endl;
    cout << fixed << setprecision(2) << mediaDiaria << endl;
    cout << fixed << setprecision(2) << maiorFaturamento << endl;

    for (int dia : diasMaior) cout << dia << " ";
    cout << endl;

    cout << fixed << setprecision(2) << menorFaturamento << endl;

    for (int dia : diasMenor) cout << dia << " ";
    cout << endl;

    return 0;
}
