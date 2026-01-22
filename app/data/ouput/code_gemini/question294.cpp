/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int X;
    double Y;
    
    std::cin >> X;
    std::cin >> Y;
    
    double consumo = X / Y;
    
    std::cout << std::fixed << std::setprecision(3);
    std::cout << consumo << " km/l" << std::endl;
    
    return 0;
}
