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
    if (n >= 0) {
        double s = 0.0;
        for (int i = 0; i <= n; ++i) {
            s += static_cast<double>(i) / (i + 1.0);
        }
        std::cout << std::fixed << std::setprecision(15) << s << std::endl;
    } else {
        n = -n;
        double p = static_cast<double>(n + 1) * (n + 2) / 2.0;
        std::cout << std::fixed << std::setprecision(15) << p << std::endl;
    }
    return 0;
}
