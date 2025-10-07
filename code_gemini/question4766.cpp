/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int num, sum = 0;
    while (std::cin >> num && num != 0) {
        if (num > 0) {
            sum += num;
        }
    }
    std::cout << "A soma dos valores eh: " << sum << std::endl;
    return 0;
}

