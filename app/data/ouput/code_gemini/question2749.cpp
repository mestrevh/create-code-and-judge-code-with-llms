/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, r;
    while (std::cin >> l >> r && (l != 0 || r != 0)) {
        std::cout << l + r << '\n';
    }
    return 0;
}
