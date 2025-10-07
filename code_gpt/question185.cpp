/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    int L, A, P, R;
    std::cin >> L >> A >> P >> R;

    int diagonal = std::sqrt(L * L + A * A + P * P);
    
    if (diagonal <= 2 * R)
        std::cout << 'S' << std::endl;
    else
        std::cout << 'N' << std::endl;

    return 0;
}
