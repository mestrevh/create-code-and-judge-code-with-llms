/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long a, b, c;
    if (std::cin >> a >> b >> c) {
        std::cout << std::max({a, b, c}) << "\n";
    }

    return 0;
}