/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Personagem {
    std::string nome;
    int id;
    int level;
    int vida;
    int ataque;
    int defesa;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    std::vector<Personagem> banco(x);

    for (int i = 0; i < x; ++i) {
        std::cin.ignore(); 
        std::getline(std::cin, banco[i].nome);
        std::cin >> banco[i].id;
        std::cin >> banco[i].level;
        std::cin >> banco[i].vida;
        std::cin >> banco[i].ataque;
        std::cin >> banco[i].defesa;
    }

    for (int i = 0; i < x; ++i) {
        std::cout << "Nome: " << banco[i].nome << "\n";
        std::cout << "ID: " << banco[i].id << "\n";
        std::cout << "Level: " << banco[i].level << "\n";
        std::cout << "Vida: " << banco[i].vida << "\n";
        std::cout << "Ataque: " << banco[i].ataque << "\n";
        std::cout << "Defesa: " << banco[i].defesa << "\n";
    }

    return 0;
}
