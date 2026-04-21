/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>
#include <cmath>

int main() {
    long long x;
    long long n;
    if (!(std::cin >> x >> n)) return 0;

    long double sum = 1.0L;
    long double term = 1.0L;

    for (long long k = 1; k <= n; k++) {
        term = term * (long double)x / (long double)k;
        sum += term;
    }

    long double exact = powl(2.7182818284590452353602874713527L, (long double)x);
    long double approx = sum;

    long double diff = fabsl(exact - approx);
    long double ratio = diff / exact;

    std::printf("%.3Lf\n", approx);

    if (ratio > 0.10L) {
        std::printf("A aproximacao foi pouco precisa\n");
    } else if (ratio >= 0.01L && ratio <= 0.10L) {
        std::printf("A aproximacao foi muito precisa\n");
    } else {
        std::printf("Os valores sao praticamente iguais\n");
    }

    return 0;
}