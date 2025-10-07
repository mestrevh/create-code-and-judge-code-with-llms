/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double encontrarMaior(double a, double b, double c, double d) {
    double maior = a;
    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }
    if (d > maior) {
        maior = d;
    }
    return maior;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double num1, num2, num3, num4;
    std::cin >> num1 >> num2 >> num3 >> num4;

    double resultado = encontrarMaior(num1, num2, num3, num4);

    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;

    return 0;
}
