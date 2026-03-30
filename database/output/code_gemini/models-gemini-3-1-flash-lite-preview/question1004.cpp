/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b;
    if (std::cin >> a >> b) {
        std::cout << (a > b ? a : b) << std::endl;
    }

    return 0;
}