/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long L, A, P, R;
    std::cin >> L >> A >> P >> R;
    if (L * L + A * A + P * P <= 4 * R * R) {
        std::cout << 'S' << '\n';
    } else {
        std::cout << 'N' << '\n';
    }
    return 0;
}
