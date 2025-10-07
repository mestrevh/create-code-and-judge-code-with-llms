/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    if (a > b) {
        std::swap(a, b);
    }
    std::cout << a << "\n";
    std::cout << b << "\n";
    return 0;
}
