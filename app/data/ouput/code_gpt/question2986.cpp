/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Evento {
public:
    int ano;
    std::string nome;

    Evento(int a, std::string n) : ano(a), nome(n) {}

    bool operator<(const Evento& other) const {
        return (ano < other.ano) || (ano == other.ano && nome < other.nome);
    }
};

int main() {
    std::list<Evento> eventos;
    std::string nome;
    int ano;

    while (std::getline(std::cin, nome)) {
        if (nome.empty())
            break;
        std::cin >> ano;
        std::cin.ignore(); // Limpa o buffer para a próxima linha
        eventos.emplace_back(ano, nome);
    }

    eventos.sort();

    for (const auto& evento : eventos) {
        std::cout << evento.ano << " - " << evento.nome << std::endl;
    }

    return 0;
}
