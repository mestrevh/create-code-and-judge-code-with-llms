/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

double dobroDoMaior(double a, double b) {
    return 2.0 * std::max(a, b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double num1, num2;
    std::cin >> num1 >> num2;
    
    double resultado = dobroDoMaior(num1, num2);
    
    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    
    return 0;
}
