/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double somar(double a, double b) {
    return a + b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b;
    std::cin >> a >> b;
    double resultado = somar(a, b);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "O resultado de " << a << " + " << b << " eh " << resultado << std::endl;
    return 0;
}
