/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double num1, num2;
    char op;

    std::cin >> num1 >> num2 >> op;

    std::cout << std::fixed << std::setprecision(2);

    switch (op) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            break;
        case '/':
            std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
            break;
        default:
            std::cout << "A operacao " << op << " eh invalida!" << std::endl;
            break;
    }

    return 0;
}
