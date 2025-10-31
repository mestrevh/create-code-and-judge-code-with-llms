/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double num1, num2;
    std::string operacao;

    std::cin >> num1 >> num2 >> operacao;

    double resultado = 0.0;

    if (operacao == "soma") {
        resultado = num1 + num2;
    } else if (operacao == "multiplicacao") {
        resultado = num1 * num2;
    } else if (operacao == "divisao") {
        if (num2 != 0) {
            resultado = num1 / num2;
        }
    } else if (operacao == "subtracao") {
        resultado = num1 - num2;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "resultado = " << resultado << std::endl;

    return 0;
}
