/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    const double PI = 3.1415;
    double r;
    
    std::cin >> r;
    
    double area = PI * r * r;
    
    std::cout << std::fixed << std::setprecision(6) << area << std::endl;
    
    return 0;
}
