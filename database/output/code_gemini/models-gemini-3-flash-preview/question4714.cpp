/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

void formarRetangulo(int largura, int altura) {
    if (largura <= 0 || altura <= 0) return;
    std::string linha(largura, '*');
    for (int i = 0; i < altura; ++i) {
        std::cout << linha << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int largura, altura;
    if (std::cin >> largura >> altura) {
        formarRetangulo(largura, altura);
    }

    return 0;
}