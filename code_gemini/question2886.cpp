/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n, m;

    while (true) {
        std::cout << "Insira o numero de linhas da matriz:" << std::endl;
        std::cin >> n;
        std::cout << "Insira o numero de colunas da matriz:" << std::endl;
        std::cin >> m;

        if (n == 0 && m == 0) {
            break;
        }

        if (n <= 0 || m <= 0) {
            continue;
        }

        long long t = 0;
        long long x = 0;
        long long a = 0;
        long long b = 0;
        long long c = 0;
        long long d = 0;

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                long long current_value = i * m + j + 1;

                t += current_value;

                if (i == j) {
                    x += current_value;
                }

                if (j == 0) {
                    a += current_value;
                }
                
                if (j == m - 1) {
                    b += current_value;
                }

                if (i == 0) {
                    c += current_value;
                }

                if (i == n - 1) {
                    d += current_value;
                }
            }
        }
        
        double result = (static_cast<double>(t) - static_cast<double>(x) + (static_cast<double>(a) * static_cast<double>(b)) - (static_cast<double>(c) * static_cast<double>(d))) / (static_cast<double>(n) * static_cast<double>(m));

        std::cout << "Valor da expressao: " << std::fixed << std::setprecision(2) << result << std::endl;
    }

    return 0;
}
