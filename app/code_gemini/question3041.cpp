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
    if (n == 0) {
        std::cout << 'E' << std::endl;
    } else if (n >= 1 && n <= 35) {
        std::cout << 'D' << std::endl;
    } else if (n >= 36 && n <= 60) {
        std::cout << 'C' << std::endl;
    } else if (n >= 61 && n <= 85) {
        std::cout << 'B' << std::endl;
    } else {
        std::cout << 'A' << std::endl;
    }
    return 0;
}
