/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double dolares;
    std::cin >> dolares;
    double reais = dolares * 3.55;
    std::cout << std::fixed << std::setprecision(2) << reais << std::endl;
    return 0;
}
