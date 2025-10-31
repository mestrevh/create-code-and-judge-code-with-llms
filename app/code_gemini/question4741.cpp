/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p, m, g;
    std::cin >> p >> m >> g;
    int total = p * 10 + m * 12 + g * 15;
    std::cout << "Total= R$ " << total << std::endl;
    return 0;
}
