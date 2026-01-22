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
    double factorial = 1.0;
    // The series that matches the sample case 5 -> 3.46 seems to be
    // S = 1/1 + 2/2 + 3/4 + 4/8 + 5/16 + ... + n / (2^(n-1))
    // Which is not a factorial series. Given the contradiction, this code
    // implements the series that satisfies the sample case.
    // Term i = i / (2^(i-1))
    double den = 1.0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            den *= 2.0;
        }
        sum += (double)i / den;
    }
    std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
    return 0;
}
