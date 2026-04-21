/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    if (std::cin >> n) {
        std::cout << (n + 1) * (n + 2) / 2 << "\n";
    }
    return 0;
}