/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Candidato {
    int numero;
    std::string nome;
    std::string sigla;
    int votos;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Candidato> candidatos(5);

    for (int i = 0; i < 5; ++i) {
        std::cin >> candidatos[i].numero;
        std::cin >> candidatos[i].nome;
        std::cin >> candidatos[i].sigla;
        candidatos[i].votos = 0;
    }

    int voto_numero;
    while (std::cin >> voto_numero && voto_numero != 0) {
        for (int i = 0; i < 5; ++i) {
            if (candidatos[i].numero == voto_numero) {
                candidatos[i].votos++;
                break;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << candidatos[i].sigla << " "
                  << candidatos[i].numero << " "
                  << candidatos[i].nome << ": "
                  << candidatos[i].votos << std::endl;
    }

    return 0;
}
