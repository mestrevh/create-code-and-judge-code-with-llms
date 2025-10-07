/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Caixa {
    int largura;
    int profundidade;
    int altura;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    bool alguma_passou = false;

    for (int i = 0; i < n; ++i) {
        Caixa c;
        std::cin >> c.largura >> c.profundidade >> c.altura;

        if (c.altura <= 10) {
            long long volume = (long long)c.largura * c.profundidade * c.altura;
            std::cout << volume << "\n";
            alguma_passou = true;
        }
    }

    if (!alguma_passou) {
        std::cout << "Nenhuma caixa passa pelo tunel!\n";
    }

    return 0;
}
