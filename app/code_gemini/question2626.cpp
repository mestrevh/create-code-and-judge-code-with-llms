/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double num;

    std::cout << std::fixed << std::setprecision(3);

    while (std::cin >> num) {
        std::cout << num << '\n';
    }

    return 0;
}
