/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

struct Personagem {
    std::string nome;
    int rating;
};

std::string transformaNome(std::string nome) {
    for (char &c : nome) {
        c = std::toupper(c);
    }
    return nome;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Personagem> personagens;

    for (int i = 0; i < n; ++i) {
        int rating;
        std::string nome;
        std::cin >> rating;
        std::getline(std::cin, nome);
        nome = transformaNome(nome.substr(1)); // Remove o espaço
        personagens.push_back({nome, rating});
    }

    auto favorito = std::max_element(personagens.begin(), personagens.end(), [](const Personagem &a, const Personagem &b) {
        return a.rating < b.rating;
    });

    auto menosFavorito = std::min_element(personagens.begin(), personagens.end(), [](const Personagem &a, const Personagem &b) {
        return a.rating < b.rating;
    });

    std::cout << "O favorito de Joao eh " << favorito->nome << " com " << favorito->rating << " rating!" << std::endl;
    std::cout << "O que Joao menos gosta eh " << menosFavorito->nome << " com " << menosFavorito->rating << " rating!" << std::endl;

    return 0;
}
