/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n < 1) {
        std::cout << "O número informado é menor que 1.\n";
    } else {
        int pattern_index = (n - 1) % 4;
        switch (pattern_index) {
            case 0: // Figure 1
                std::cout << "Esquerda superior: vermelho\n";
                std::cout << "Direita superior: amarelo\n";
                std::cout << "Esquerda inferior: azul\n";
                std::cout << "Direita inferior: verde\n";
                break;
            case 1: // Figure 2
                std::cout << "Esquerda superior: azul\n";
                std::cout << "Direita superior: vermelho\n";
                std::cout << "Esquerda inferior: verde\n";
                std::cout << "Direita inferior: amarelo\n";
                break;
            case 2: // Figure 3
                std::cout << "Esquerda superior: verde\n";
                std::cout << "Direita superior: azul\n";
                std::cout << "Esquerda inferior: amarelo\n";
                std::cout << "Direita inferior: vermelho\n";
                break;
            case 3: // Figure 4
                std::cout << "Esquerda superior: amarelo\n";
                std::cout << "Direita superior: verde\n";
                std::cout << "Esquerda inferior: vermelho\n";
                std::cout << "Direita inferior: azul\n";
                break;
        }
    }

    return 0;
}
