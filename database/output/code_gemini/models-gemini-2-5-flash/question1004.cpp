/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm> // Para std::max

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double num1, num2;
    std::cin >> num1 >> num2;
    std::cout << std::max(num1, num2) << std::endl;

    return 0;
}