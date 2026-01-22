/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l, c;
    std::cin >> l >> c;
    char letra_busca;
    std::cin >> letra_busca;
    int valor_letra = static_cast<int>(letra_busca);
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            int valor_matriz;
            std::cin >> valor_matriz;
            if (valor_matriz == valor_letra) {
                char linha_letra = 'A' + i;
                int coluna_numero = j + 1;
                std::cout << linha_letra << coluna_numero << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
