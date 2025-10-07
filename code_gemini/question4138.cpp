/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double a, b;
    int op;

    std::cin >> a >> b >> op;

    double resultado;

    switch (op) {
        case 1:
            resultado = a + b;
            break;
        case 2:
            resultado = a - b;
            break;
        case 3:
            resultado = a * b;
            break;
        case 4:
            resultado = a / b;
            break;
    }

    std::cout << std::fixed << std::setprecision(3) << resultado << std::endl;

    return 0;
}
