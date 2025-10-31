/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double peso_livro;
    double peso_total = 0.0;
    int contador_livros = 0;
    const double CAPACIDADE_MAXIMA = 18.0;

    std::cout << "Insira o peso dos livros:" << std::endl;

    while (std::cin >> peso_livro) {
        if (peso_total + peso_livro <= CAPACIDADE_MAXIMA) {
            peso_total += peso_livro;
            contador_livros++;
        } else {
            break;
        }
    }

    std::cout << "Podem ser carregados " << contador_livros << " livros." << std::endl;

    return 0;
}
