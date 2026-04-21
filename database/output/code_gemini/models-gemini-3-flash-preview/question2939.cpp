/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long x, a, b, c;
    while (std::cin >> x >> a >> b >> c) {
        if ((a + b - c) > 2 * x) {
            std::cout << "O Pokemon pode ser derrotado!\n";
        } else {
            std::cout << "Melhor nao arriscar\n";
        }
    }

    return 0;
}