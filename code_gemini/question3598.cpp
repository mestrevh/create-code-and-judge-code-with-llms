/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, a, b;
    std::cin >> m >> a >> b;
    int c = m - a - b;
    int oldest = std::max({a, b, c});
    std::cout << oldest << std::endl;
    return 0;
}
