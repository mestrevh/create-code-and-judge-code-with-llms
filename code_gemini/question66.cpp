/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double capital, taxa;
    int anos;

    std::cin >> capital >> taxa >> anos;

    std::cout << std::fixed << std::setprecision(2);

    int total_trimestres = anos * 4;
    double montante = capital;

    for (int i = 0; i < total_trimestres; ++i) {
        double rendimento = montante * taxa;
        montante += rendimento;
        std::cout << "Rendimento: " << rendimento << " Montante: " << montante << std::endl;
    }

    return 0;
}
