/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n % 10 != 0 && n % (n / 10) == 0) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }
    return 0;
}
