/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;

    if (n1 < 0 || n1 > 100 || n2 < 0 || n2 > 100 || n3 < 0 || n3 > 100) {
        std::cout << "Media invalida\n";
    } else {
        double media = (n1 + n2 + n3) / 3.0;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "A media do aluno foi " << media << " e ele foi ";

        if (media >= 70.0) {
            std::cout << "APROVADO\n";
        } else if (media > 40.0) {
            std::cout << "FINAL\n";
        } else {
            std::cout << "REPROVADO\n";
        }
    }

    return 0;
}
