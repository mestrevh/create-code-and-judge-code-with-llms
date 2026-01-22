/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

long long getMax(long long seed, long long mult, long long add, long long mod) {
    long long max_val = seed;
    long long current_val = seed;
    for (int i = 1; i < 10; ++i) {
        current_val = (current_val * mult + add) % mod;
        if (current_val > max_val) {
            max_val = current_val;
        }
    }
    return max_val;
}

void Modulo(int* soma, int A, int B, int C) {
    int divisor = (A / B) + C;
    if (divisor != 0) {
        *soma = *soma % divisor;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long A, B, C, seedX, seedY, seedZ;
    if (!(std::cin >> A >> B >> C >> seedX >> seedY >> seedZ)) {
        return 1;
    }

    int maxY = getMax(seedY, A, B, C);
    int maxX = getMax(seedX, B, C, A);
    int maxZ = getMax(seedZ, C, A, B);

    int soma = maxX + maxY + maxZ;

    Modulo(&soma, A, B, C);

    std::cout << soma << std::endl;

    return 0;
}
