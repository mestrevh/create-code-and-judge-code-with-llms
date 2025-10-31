/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void print_row(int r, int i) {
    int dots = r - 1 - i;
    int stars = i + 1;

    for (int j = 0; j < dots; ++j) {
        std::cout << ".";
    }

    for (int j = 0; j < stars; ++j) {
        std::cout << "*";
        if (j < stars - 1) {
            std::cout << ".";
        }
    }

    for (int j = 0; j < dots; ++j) {
        std::cout << ".";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int r;
    std::cin >> r;

    for (int i = 0; i < r; ++i) {
        print_row(r, i);
    }

    for (int i = r - 2; i >= 0; --i) {
        print_row(r, i);
    }

    return 0;
}
