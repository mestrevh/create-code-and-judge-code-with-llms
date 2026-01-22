/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool first = true;
    for (int i = 1500; i <= 2700; ++i) {
        if (i % 5 == 0 && i % 7 == 0) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << i;
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
