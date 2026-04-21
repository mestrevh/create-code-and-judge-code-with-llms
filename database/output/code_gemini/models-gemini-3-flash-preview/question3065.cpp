/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double largura, altura;
    if (std::cin >> largura >> altura) {
        double diagonal = std::hypot(largura, altura);
        std::cout << std::fixed << std::setprecision(1) << diagonal << std::endl;
    }

    return 0;
}