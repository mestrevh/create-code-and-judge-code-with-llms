/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int encontrarMaior(int a, int b, int c) {
    return std::max({a, b, c});
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << encontrarMaior(x, y, z) << std::endl;
    return 0;
}
