/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x1, x2;
    std::cin >> x1 >> x2;
    long long p = (long long)x1 * x2;
    std::cout << "O produto entre " << x1 << " e " << x2 << " é dado por: " << p << std::endl;
    return 0;
}
