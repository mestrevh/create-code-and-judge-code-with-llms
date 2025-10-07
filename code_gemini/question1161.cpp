/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int maximo(int a, int b) {
    return (a + b + std::abs(a - b)) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, L, P;
    int H;

    std::cin >> A >> L >> P;
    std::cin >> H;

    int total_A = A * H;
    int total_L = L * H;
    int total_P = P * H;

    int max_parcial = maximo(total_A, total_L);
    int max_final = maximo(max_parcial, total_P);

    std::cout << max_final << std::endl;

    return 0;
}
