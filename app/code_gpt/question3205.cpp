/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double total;
    std::cin >> total;

    int c_and_a = static_cast<int>(total / 3);
    double felipe_part = total - (c_and_a * 2);
    
    std::cout << std::fixed << std::setprecision(2) << c_and_a << std::endl;
    std::cout << std::fixed << std::setprecision(2) << c_and_a << std::endl;
    std::cout << std::fixed << std::setprecision(2) << felipe_part << std::endl;

    return 0;
}
