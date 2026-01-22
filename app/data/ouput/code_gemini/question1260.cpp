/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

struct Livro {
    std::string linhaCompleta;
    int identificador;
};

bool compararLivros(const Livro& a, const Livro& b) {
    return a.identificador < b.identificador;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::cin.ignore(); 

    std::vector<Livro> livros(N);

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, livros[i].linhaCompleta);
        size_t pos = livros[i].linhaCompleta.find('#');
        if (pos != std::string::npos) {
            livros[i].identificador = std::stoi(livros[i].linhaCompleta.substr(pos + 1));
        }
    }

    std::sort(livros.begin(), livros.end(), compararLivros);

    for (int i = 0; i < N; ++i) {
        std::cout << livros[i].linhaCompleta << '\n';
    }

    return 0;
}
