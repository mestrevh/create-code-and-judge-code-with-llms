/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int dividend, divisor;
    std::cin >> dividend >> divisor;

    int quotient = 0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }

    std::cout << quotient * sign << std::endl;
    return 0;
}
