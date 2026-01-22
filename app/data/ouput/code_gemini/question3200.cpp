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
    
    double radius, height;
    std::cin >> radius >> height;
    
    double volume = M_PI * radius * radius * height;
    
    std::cout << std::fixed << std::setprecision(15) << volume << std::endl;
    
    return 0;
}
