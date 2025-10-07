/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    long long N, K;
    std::cin >> N >> K;
    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    N--; // Remover o computador já instalado
    long long hours = 0;
    
    while (N > 0) {
        hours++;
        N -= K;
        K *= 2; // Duplicar cabeamento a cada hora
    }
    
    std::cout << hours << std::endl;
    return 0;
}
