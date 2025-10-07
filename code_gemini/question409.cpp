/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int SerieMiguelito(int n) {
    if (n == 1) {
        return 3;
    }
    if (n % 2 == 0) {
        return SerieMiguelito(n - 1) + 4;
    } else {
        return SerieMiguelito(n - 1) + 1;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << SerieMiguelito(n) << std::endl;
    return 0;
}
