/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    double sum = 0.0;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            sum -= 1.0 / i;
        } else {
            sum += 1.0 / i;
        }
    }
    
    std::cout << std::fixed << std::setprecision(6) << sum << std::endl;
    return 0;
}
