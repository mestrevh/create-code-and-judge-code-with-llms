/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int option;
    std::cin >> option;

    if (option == 1) {
        double num1, num2;
        std::cin >> num1 >> num2;
        double sum = num1 + num2;
        std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
    } else if (option == 2) {
        double num;
        std::cin >> num;
        double root = sqrt(num);
        std::cout << std::fixed << std::setprecision(2) << root << std::endl;
    } else {
        std::cout << "Opção inválida!" << std::endl;
    }

    return 0;
}
