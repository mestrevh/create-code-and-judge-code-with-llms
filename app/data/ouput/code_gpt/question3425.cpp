/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> v(n);
    double menor = 1e9, maior = -1e9, soma = 0;
    int contPares = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        if (v[i] < menor) menor = v[i];
        if (v[i] > maior) maior = v[i];
        if (static_cast<int>(v[i]) % 2 == 0) contPares++;
        soma += v[i];
    }

    double percentualPares = (static_cast<double>(contPares) / n) * 100;
    double media = soma / n;

    std::cout << std::fixed << std::setprecision(1) << menor << std::endl;
    std::cout << std::fixed << std::setprecision(1) << maior << std::endl;
    std::cout << std::fixed << std::setprecision(2) << percentualPares << std::endl;
    std::cout << std::fixed << std::setprecision(2) << media << std::endl;

    return 0;
}
