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
        if (i % 2 != 0) {
            sum -= 1.0 / i;
        } else {
            sum += 1.0 / i;
        }
    }
    std::cout << std::fixed << std::setprecision(6) << sum << std::endl;
    return 0;
}
