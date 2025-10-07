/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::cin >> line;

    for (char &c : line) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }

    std::stringstream ss(line);
    int num;

    if (!(ss >> num)) {
        return 0;
    }

    int maior = num;
    int menor = num;
    long long soma = num;
    int contador = 1;

    while (ss >> num) {
        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
        soma += num;
        contador++;
    }

    double media = static_cast<double>(soma) / contador;

    std::cout << "Maior: " << maior << std::endl;
    std::cout << "Menor: " << menor << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Media: " << media << std::endl;

    return 0;
}
