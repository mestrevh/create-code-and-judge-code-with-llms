/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int hamburguer, cheeseburger, fritas, refrigerante, milkshake;
    std::cin >> hamburguer >> cheeseburger >> fritas >> refrigerante >> milkshake;
    
    float total = hamburguer * 3.0 + cheeseburger * 2.5 + fritas * 2.5 + refrigerante * 1.0 + milkshake * 3.0;
    
    std::cout << std::fixed << std::setprecision(1) << "conta final: " << total << std::endl;
    return 0;
}
