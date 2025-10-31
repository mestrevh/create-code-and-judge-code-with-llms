/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int x;
    std::cin >> x;
    double y = -2.0 * x * x + 6.0 * x - 1.0;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Y= " << y << std::endl;
    return 0;
}
