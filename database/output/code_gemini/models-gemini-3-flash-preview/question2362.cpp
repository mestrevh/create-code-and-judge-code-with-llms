/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long h, m, s;
    if (std::cin >> h >> m >> s) {
        long long total = (h * 3600LL) + (m * 60LL) + s;
        std::cout << total << "\n";
    }
    return 0;
}
