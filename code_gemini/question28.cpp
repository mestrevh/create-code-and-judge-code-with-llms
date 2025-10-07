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
    int digit1 = n / 10;
    int digit2 = n % 10;
    int reversed_n = digit2 * 10 + digit1;
    std::cout << reversed_n << std::endl;
    return 0;
}
