/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int L, C;
    char X;
    std::cin >> L >> C >> X;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << X;
        }
        std::cout << '\n';
    }
    return 0;
}
