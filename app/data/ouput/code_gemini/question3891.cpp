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

    double media_simples = (n1 + n2 + n3) / 3.0;
    double media_ponderada1 = (n1 * 2.0 + n2 * 2.0 + n3 * 3.0) / 7.0;
    double media_ponderada2 = (n1 * 1.0 + n2 * 2.0 + n3 * 2.0) / 5.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << media_simples << std::endl;
    std::cout << media_ponderada1 << std::endl;
    std::cout << media_ponderada2 << std::endl;

    return 0;
}
