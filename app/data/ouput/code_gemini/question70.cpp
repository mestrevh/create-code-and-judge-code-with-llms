/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double x;
    int n;

    while (std::cin >> x >> n && (x != 0 || n != 0)) {
        double sum = 0.0;
        double factorial = 1.0;
        
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
            if (i % 2 != 0) {
                sum += x / factorial;
            } else {
                sum -= x / factorial;
            }
        }
        
        std::cout << std::fixed << std::setprecision(6) << sum << std::endl;
    }

    return 0;
}
