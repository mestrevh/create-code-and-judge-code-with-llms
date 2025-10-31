/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int increment(int n) {
    int first_digit = n;
    while (first_digit >= 10) {
        first_digit /= 10;
    }
    return (first_digit % 2 == 0) ? n + 2 : n + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << increment(n) << std::endl;
    return 0;
}
