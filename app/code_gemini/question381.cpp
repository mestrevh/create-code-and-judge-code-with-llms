/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const double CAPACIDADE_MAXIMA = 18.0;
    double peso_total = 0.0;
    int contador_livros = 0;
    double peso_livro_atual;

    while (std::cin >> peso_livro_atual) {
        if (peso_total + peso_livro_atual <= CAPACIDADE_MAXIMA) {
            peso_total += peso_livro_atual;
            contador_livros++;
        } else {
            break;
        }
    }

    std::cout << contador_livros << std::endl;

    return 0;
}
