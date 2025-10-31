/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

double calcularSalario(int pecas, double salario_minimo) {
    if (pecas <= 30) {
        return salario_minimo;
    } else if (pecas <= 41) {
        int excesso = pecas - 30;
        return salario_minimo + (0.03 * salario_minimo * excesso);
    } else {
        int excesso = pecas - 30;
        return salario_minimo + (0.05 * salario_minimo * excesso);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salario_minimo;
    std::cin >> salario_minimo;

    int pecas1, pecas2, pecas3;
    std::cin >> pecas1 >> pecas2 >> pecas3;

    double salario1 = calcularSalario(pecas1, salario_minimo);
    double salario2 = calcularSalario(pecas2, salario_minimo);
    double salario3 = calcularSalario(pecas3, salario_minimo);

    int total_pecas = pecas1 + pecas2 + pecas3;
    double media_pecas = static_cast<double>(total_pecas) / 3.0;
    double maior_salario = std::max({salario1, salario2, salario3});

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Salario 1: " << salario1 << std::endl;
    std::cout << "Salario 2: " << salario2 << std::endl;
    std::cout << "Salario 3: " << salario3 << std::endl;
    std::cout << "Total de pecas fabricadas: " << total_pecas << std::endl;
    std::cout << "Media de pecas fabricadas: " << media_pecas << std::endl;
    std::cout << "Maior salario: " << maior_salario << std::endl;

    return 0;
}
