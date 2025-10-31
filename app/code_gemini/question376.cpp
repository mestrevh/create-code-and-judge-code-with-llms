/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int livros, alunos;
    std::cin >> livros >> alunos;
    double ratio = static_cast<double>(alunos) / livros;
    if (ratio <= 8) {
        std::cout << "A\n";
    } else if (ratio <= 12) {
        std::cout << "B\n";
    } else if (ratio <= 18) {
        std::cout << "C\n";
    } else {
        std::cout << "D\n";
    }
    return 0;
}
