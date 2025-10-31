/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char tipo;
    std::cin >> tipo;

    if (tipo != 'a' && tipo != 'p' && tipo != 'h') {
        std::cout << "Caractere invalido" << std::endl;
        return 0;
    }

    double n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;

    if (n1 < 1.0 || n1 > 10.0 || n2 < 1.0 || n2 > 10.0 || n3 < 1.0 || n3 > 10.0) {
        std::cout << "Notas erradas" << std::endl;
        return 0;
    }

    double media = 0.0;

    if (tipo == 'a') {
        media = (n1 + n2 + n3) / 3.0;
    } else if (tipo == 'p') {
        double p1, p2, p3;
        std::cin >> p1 >> p2 >> p3;
        media = (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3);
    } else { // tipo == 'h'
        media = 3.0 / (1.0 / n1 + 1.0 / n2 + 1.0 / n3);
    }

    std::cout << std::fixed << std::setprecision(2) << media << std::endl;

    if (media >= 7.0) {
        std::cout << "Aprovado" << std::endl;
    } else if (media > 4.0) {
        std::cout << "Prova final" << std::endl;
    } else {
        std::cout << "Reprovado" << std::endl;
    }

    return 0;
}
