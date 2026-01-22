/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int nthRoot(int a, int b) {
    return static_cast<int>(pow(a, 1.0 / b));
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << nthRoot(a, b) << std::endl;
    return 0;
}
