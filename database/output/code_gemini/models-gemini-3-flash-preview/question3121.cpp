/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long L, A;
    if (std::cin >> L >> A) {
        std::cout << (L * L * A) << "\n";
    }
    return 0;
}