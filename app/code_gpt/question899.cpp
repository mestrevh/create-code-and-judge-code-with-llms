/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>

int main() {
    double num, max_num = std::numeric_limits<double>::lowest();
    
    for (int i = 0; i < 50; i++) {
        std::cout << "Digite um numero: ";
        std::cin >> num;
        if (num > max_num) {
            max_num = num;
        }
    }
    
    std::cout << "Maior numero: " << max_num << std::endl;
    return 0;
}
