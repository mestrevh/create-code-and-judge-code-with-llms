/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nome;
    int pontuacao;

    std::string menor_nome;
    int menor_pontuacao;
    std::string maior_nome;
    int maior_pontuacao;

    double soma_pontos = 0.0;
    int contador_jogadores = 0;

    while (std::cin >> nome) {
        if (nome == "sair") {
            break;
        }

        std::cin >> pontuacao;
        contador_jogadores++;
        soma_pontos += pontuacao;

        if (contador_jogadores == 1) {
            menor_pontuacao = pontuacao;
            maior_pontuacao = pontuacao;
            menor_nome = nome;
            maior_nome = nome;
        } else {
            if (pontuacao <= menor_pontuacao) {
                menor_pontuacao = pontuacao;
                menor_nome = nome;
            }
            if (pontuacao >= maior_pontuacao) {
                maior_pontuacao = pontuacao;
                maior_nome = nome;
            }
        }
    }

    if (contador_jogadores == 0) {
        std::cout << "Nenhum jogador foi registrado." << std::endl;
    } else {
        std::cout << menor_nome << std::endl;
        std::cout << maior_nome << std::endl;
        double media = soma_pontos / contador_jogadores;
        std::cout << std::fixed << std::setprecision(2) << media << std::endl;
    }

    return 0;
}
