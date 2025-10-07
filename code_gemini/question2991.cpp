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
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (static_cast<double>(i) * i);
    }
    std::cout << std::fixed << std::setprecision(6) << sum << std::endl;
    return 0;
}
