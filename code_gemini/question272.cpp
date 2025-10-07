/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    long long num;
    long long prod = 1;
    while (std::cin >> num) {
        prod *= num;
    }
    std::cout << "Prod = " << prod << std::endl;
    return 0;
}
