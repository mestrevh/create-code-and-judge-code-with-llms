/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, y;
    std::cin >> x >> y;

    std::cout << std::uppercase << std::hex;

    std::cout << "X = " << (x - 1) + (x + 1) << '\n';
    std::cout << "Y = " << (y - 1) + (y + 1) << '\n';

    return 0;
}
