/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int D;
    std::string N;
    while (std::cin >> D >> N, D != 0) {
        N.erase(remove(N.begin(), N.end(), '0' + D), N.end());
        if (N.empty()) N = "0";
        std::cout << N << "\n";
    }
    return 0;
}
