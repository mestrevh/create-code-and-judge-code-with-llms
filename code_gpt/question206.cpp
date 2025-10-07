/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    long long A, B, C, X, Y, Z;
    std::cin >> A >> B >> C >> X >> Y >> Z;

    if (C > Z) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long fitLength = X / A;
    long long fitWidth = Y / B;
    
    long long count1 = fitLength * fitWidth;

    fitLength = X / B;
    fitWidth = Y / A;

    long long count2 = fitLength * fitWidth;

    std::cout << std::max(count1, count2) << std::endl;

    return 0;
}
