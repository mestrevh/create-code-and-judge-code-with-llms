/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int m, n;
    std::cin >> m >> n;
    if (m > n) {
        std::cout << "sem multiplos menores que " << n << std::endl;
    } else {
        int result = (n / m) * m;
        std::cout << result << std::endl;
    }
    return 0;
}
