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

    double sum_of_squares = (n1 * n1) + (n2 * n2) + (n3 * n3);
    double sum = n1 + n2 + n3;
    double square_of_sum = sum * sum;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << sum_of_squares << std::endl;
    std::cout << square_of_sum << std::endl;

    return 0;
}
