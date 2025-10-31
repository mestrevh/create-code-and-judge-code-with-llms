/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore();
    for (int i = 1; i <= T; ++i) {
        std::string X;
        std::getline(std::cin, X);
        std::sort(X.rbegin(), X.rend());
        std::cout << "Caso " << i << ": " << X << std::endl;
    }
    return 0;
}
