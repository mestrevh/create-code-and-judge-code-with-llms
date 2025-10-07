/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int start, end;

    std::cin >> start;
    while (start < 1 || start > 9) {
        std::cout << "Insira um número inicial entre 1 e 9\n";
        std::cin >> start;
    }

    std::cin >> end;
    while (end < 1 || end > 9) {
        std::cout << "Insira um número final entre 1 e 9\n";
        std::cin >> end;
    }

    if (start > end) {
        std::cout << "Nenhuma tabuada nesse intervalo\n";
    } else {
        for (int i = start; i <= end; ++i) {
            for (int j = 1; j <= 9; ++j) {
                std::cout << i << " x " << j << " = " << i * j << "\n";
            }
            if (i < end) {
                std::cout << "\n";
            }
        }
    }

    return 0;
}
