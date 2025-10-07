/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    char a, b;
    std::cin >> a >> b;

    if (a > b) std::swap(a, b);

    for (char c = a + 1; c < b; ++c) {
        std::cout << c << std::endl;
    }

    return 0;
}
