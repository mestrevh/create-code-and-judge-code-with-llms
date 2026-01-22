/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;

    if (n < 3) {
        std::cout << "Valor invalido" << std::endl;
        return 0;
    }

    double f_prev = 0.0;
    double f_curr = 1.0;

    for (int i = 3; i <= n; ++i) {
        double f_next = f_curr + f_prev;
        f_prev = f_curr;
        f_curr = f_next;
    }

    double ratio = f_curr / f_prev;

    std::cout << std::fixed << std::setprecision(15) << ratio << std::endl;

    return 0;
}
