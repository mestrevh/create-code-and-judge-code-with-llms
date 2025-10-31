/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::unordered_set<std::string> livros;
    std::cin.ignore();
    std::string livro;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, livro);
        livros.insert(livro);
    }

    std::getline(std::cin, livro);
    std::cout << (livros.count(livro) ? "Sim" : "Não") << std::endl;

    return 0;
}
