/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int main() {
    std::vector<double> fx;
    for (double x = -5; x <= 5; x += 0.5) {
        fx.push_back(sin(x + 0.5));
    }
    
    std::cout << "fx = \n";
    for (size_t i = 0; i < fx.size(); ++i) {
        std::cout << std::fixed << std::setprecision(5) << fx[i];
        if ((i + 1) % 8 == 0 && i + 1 != fx.size()) {
            std::cout << "\n ";
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
