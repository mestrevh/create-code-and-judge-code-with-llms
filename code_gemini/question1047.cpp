/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n1, n2, n3;
    double w1, w2, w3;

    std::cin >> n1 >> n2 >> n3;
    std::cin >> w1 >> w2 >> w3;

    double media_a = (n1 + n2 + n3) / 3.0;
    double media_p = (n1 * w1 + n2 * w2 + n3 * w3) / (w1 + w2 + w3);
    double media_h = 3.0 / (1.0 / n1 + 1.0 / n2 + 1.0 / n3);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "a: " << media_a << std::endl;
    std::cout << "p: " << media_p << std::endl;
    std::cout << "h: " << media_h << std::endl;

    return 0;
}
