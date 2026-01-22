/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(3);

    double accumulator, operand;
    char operation;

    std::cin >> accumulator;

    while (std::cin >> operand >> operation && operation != '&') {
        if (operation == '+') {
            accumulator += operand;
        } else if (operation == '-') {
            accumulator -= operand;
        } else if (operation == '*') {
            accumulator *= operand;
        } else if (operation == '/') {
            if (operand == 0) {
                std::cout << "operacao nao pode ser realizada\n";
                return 0;
            }
            accumulator /= operand;
        }
        std::cout << accumulator << "\n";
    }

    return 0;
}
