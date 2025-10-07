/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

unsigned int sum_digits(unsigned int n) {
    unsigned int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    unsigned int n;
    std::cin >> n;
    std::cout << sum_digits(n) << std::endl;
    return 0;
}
