/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double peso, altura;
    if (std::cin >> peso >> altura) {
        double imc = peso / (altura * altura);
        std::cout << std::fixed << std::setprecision(1) << imc << "\n";
    }

    return 0;
}