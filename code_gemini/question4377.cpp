/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void drawSuperior(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2 * (n - i); ++j) {
            std::cout << " ";
        }
        int num_stars = 2 * i - 1;
        if (num_stars > 0) {
            std::cout << "*";
            for (int k = 1; k < num_stars; ++k) {
                std::cout << " *";
            }
        }
        std::cout << "\n";
    }
}

void drawInferior(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < 2 * (n - i); ++j) {
            std::cout << " ";
        }
        int num_stars = 2 * i - 1;
        if (num_stars > 0) {
            std::cout << "*";
            for (int k = 1; k < num_stars; ++k) {
                std::cout << " *";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    char k;
    std::cin >> n >> k;
    if (k == 'S') {
        drawSuperior(n);
    } else if (k == 'I') {
        drawInferior(n);
    } else if (k == 'T') {
        drawSuperior(n);
        drawInferior(n);
    }
    return 0;
}
