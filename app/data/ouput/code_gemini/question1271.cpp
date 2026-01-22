/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        std::cout << std::setw(3) << i;
        if (i % M == 0 || i == N) {
            std::cout << '\n';
        } else {
            std::cout << " ";
        }
    }
    return 0;
}
