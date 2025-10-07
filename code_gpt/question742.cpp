/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string A, B;
    std::getline(std::cin, A);
    std::getline(std::cin, B);
    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    std::cout << B << " " << A << std::endl;
    return 0;
}
