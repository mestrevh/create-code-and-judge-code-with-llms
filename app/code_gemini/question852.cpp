/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <cmath>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a / gcd(a, b)) * b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    std::vector<long long> times_int(n);
    for (int i = 0; i < n; ++i) {
        double t;
        std::cin >> t;
        times_int[i] = static_cast<long long>(round(t * 10.0));
    }

    long long result_lcm = times_int[0];
    for (int i = 1; i < n; ++i) {
        result_lcm = lcm(result_lcm, times_int[i]);
    }

    double final_time = static_cast<double>(result_lcm) / 10.0;

    std::cout << "O tempo para o alinhamento dos planetas e "
              << std::fixed << std::setprecision(1) << final_time
              << " minutos" << std::endl;

    return 0;
}
