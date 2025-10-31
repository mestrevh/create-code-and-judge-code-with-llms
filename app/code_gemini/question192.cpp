/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N;
    std::cin >> N;

    long long P, Q, R, S, X, Y;
    std::cin >> P >> Q >> R >> S >> X >> Y;

    long long I, J;
    std::cin >> I >> J;

    long long C_IJ = 0;

    for (long long k = 1; k <= N; ++k) {
        long long A_Ik = (P * I + Q * k) % X;
        long long B_kJ = (R * k + S * J) % Y;
        C_IJ += A_Ik * B_kJ;
    }

    std::cout << C_IJ << std::endl;

    return 0;
}
