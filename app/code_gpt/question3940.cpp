/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double calcularSalario(double salarioMinimo, int pecas) {
    if (pecas <= 30) return salarioMinimo;
    if (pecas <= 41) return salarioMinimo + (pecas - 30) * 0.03 * salarioMinimo;
    return salarioMinimo + (pecas - 30) * 0.05 * salarioMinimo;
}

int main() {
    double salarioMinimo;
    cin >> salarioMinimo;

    vector<int> pecas(3);
    vector<double> salarios(3);
    int totalPecas = 0;
    double maiorSalario = 0;

    for (int i = 0; i < 3; i++) {
        cin >> pecas[i];
        salarios[i] = calcularSalario(salarioMinimo, pecas[i]);
        totalPecas += pecas[i];
        maiorSalario = max(maiorSalario, salarios[i]);
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++) {
        cout << "Salario " << i + 1 << ": " << salarios[i] << endl;
    }
    cout << "Total de pecas fabricadas: " << totalPecas << endl;
    cout << "Media de pecas fabricadas: " << static_cast<double>(totalPecas) / 3 << endl;
    cout << "Maior salario: " << maiorSalario << endl;

    return 0;
}
