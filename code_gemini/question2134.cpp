/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0 || n > 5) {
        std::cout << "Numero de notas invalido." << std::endl;
        return 0;
    }

    std::vector<float> notas(n);
    float soma = 0.0f;

    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
        soma += notas[i];
    }

    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < n; ++i) {
        std::cout << "Nota " << i + 1 << ": " << notas[i] << std::endl;
    }

    float media = 0.0f;
    if (n > 0) {
        media = soma / n;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Media: " << media << std::endl;

    return 0;
}
