/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double nota;
    if (std::cin >> nota) {
        std::cout << std::fixed << std::setprecision(1) << "Nota digitada: " << nota << "\n";
        if (nota < 0.0 || nota > 10.0) {
            std::cout << "A nota nao esta no intervalo [0,10]\n";
        }
    }

    return 0;
}