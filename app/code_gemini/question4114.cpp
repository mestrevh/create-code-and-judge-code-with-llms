/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int year;
    std::cin >> year;
    if (isLeapYear(year)) {
        std::cout << "eh bissexto";
    } else {
        std::cout << "nao eh bissexto";
    }
    return 0;
}
