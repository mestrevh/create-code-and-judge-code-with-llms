/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<double> alturas(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> alturas[i];
    }
    
    std::sort(alturas.begin(), alturas.end());
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << alturas[0] << std::endl;
    std::cout << alturas[2] << std::endl;
    std::cout << alturas[3] << std::endl;
    std::cout << alturas[1] << std::endl;
    
    return 0;
}
