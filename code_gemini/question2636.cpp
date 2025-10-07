/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int livros, alunos;

    std::cout << "Digite a quantidade de livros:" << std::endl;
    std::cin >> livros;
    std::cout << "Digite a quantidade de alunos:" << std::endl;
    std::cin >> alunos;

    double ratio = 0.0;
    if (livros > 0) {
        ratio = static_cast<double>(alunos) / livros;
    }

    std::cout << "Numero de alunos por livro: " << ratio << ". Conceito ";

    char conceito;
    if (ratio <= 8) {
        conceito = 'A';
    } else if (ratio >= 9 && ratio <= 12) {
        conceito = 'B';
    } else if (ratio >= 13 && ratio <= 18) {
        conceito = 'C';
    } else {
        conceito = 'D';
    }

    std::cout << conceito << " no MEC." << std::endl;

    return 0;
}
