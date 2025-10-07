/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    int n1, n2;
    while (std::cin >> n1 >> n2) {
        int result1 = static_cast<int>(pow(n1, n1)) % 100;
        int result2 = static_cast<int>(pow(n2, n2)) % 100;
        
        if (result1 > result2) {
            std::cout << n1 << std::endl;
        } else if (result2 > result1) {
            std::cout << n2 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
    return 0;
}
