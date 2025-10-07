/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int reversed_n = 0;
    while (n > 0) {
        int digit = n % 10;
        reversed_n = reversed_n * 10 + digit;
        n /= 10;
    }
    std::cout << reversed_n << std::endl;
    return 0;
}
