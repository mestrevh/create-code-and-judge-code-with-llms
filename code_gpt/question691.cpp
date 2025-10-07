/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
