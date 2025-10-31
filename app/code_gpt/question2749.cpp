/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int L, R;
    while (true) {
        std::cin >> L >> R;
        if (L == 0 && R == 0) break;
        std::cout << (L + R) << std::endl;
    }
    return 0;
}
