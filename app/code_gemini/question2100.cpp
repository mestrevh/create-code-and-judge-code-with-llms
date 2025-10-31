/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string binary_string;
    std::cin >> binary_string;
    long long decimal_value = 0;
    for (char digit : binary_string) {
        decimal_value = (decimal_value << 1) | (digit - '0');
    }
    std::cout << decimal_value << std::endl;
    return 0;
}
