/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long Q, R, S;
    while (std::cin >> Q >> R >> S) {
        long long x = Q + (S - 1) * R;
        std::cout << "Na semana " << S << " Soneca tera que fazer " << x << " questoes!" << std::endl;
    }
    return 0;
}
