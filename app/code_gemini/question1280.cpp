/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    char x_char, i_char, op, j_char;
    std::cin >> m >> x_char >> n;
    int x_coeff, y_coeff;
    std::cin >> x_coeff >> i_char >> op >> y_coeff >> j_char;
    long long product = 1;
    int diagonal_size = std::min(m, n);
    for (int k = 1; k <= diagonal_size; ++k) {
        long long element_value;
        if (op == '+') {
            element_value = (long long)x_coeff * k + (long long)y_coeff * k;
        } else {
            element_value = (long long)x_coeff * k - (long long)y_coeff * k;
        }
        product *= element_value;
    }
    std::cout << product << std::endl;
    return 0;
}
