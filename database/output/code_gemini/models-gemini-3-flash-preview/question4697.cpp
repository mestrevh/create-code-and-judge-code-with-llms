/*
Código criado pelo models/gemini-3-flash-preview
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
    if (std::cin >> a >> b) {
        std::cout << std::fixed << std::setprecision(1) 
                  << "O resultado de " << a << " + " << b << " eh " << somar(a, b) << std::endl;
    }

    return 0;
}