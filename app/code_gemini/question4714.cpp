/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void formarRetangulo(int largura, int altura) {
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int largura, altura;
    std::cin >> largura >> altura;
    formarRetangulo(largura, altura);
    return 0;
}
