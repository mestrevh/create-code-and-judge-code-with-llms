/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, nulos;
    std::cin >> a >> b >> c >> nulos;

    double total = a + b + c + nulos;

    if (total == 0) {
        std::cout << "Candidato A: 0%" << std::endl;
        std::cout << "Candidato B: 0%" << std::endl;
        std::cout << "Candidato C: 0%" << std::endl;
        std::cout << "Nulos: 0%" << std::endl;
        return 0;
    }

    double perc_a = (static_cast<double>(a) / total) * 100.0;
    double perc_b = (static_cast<double>(b) / total) * 100.0;
    double perc_c = (static_cast<double>(c) / total) * 100.0;
    double perc_nulos = (static_cast<double>(nulos) / total) * 100.0;

    std::cout << "Candidato A: " << static_cast<int>(perc_a) << "%" << std::endl;
    std::cout << "Candidato B: " << static_cast<int>(perc_b) << "%" << std::endl;
    std::cout << "Candidato C: " << static_cast<int>(perc_c) << "%" << std::endl;
    std::cout << "Nulos: " << static_cast<int>(perc_nulos) << "%" << std::endl;

    return 0;
}
