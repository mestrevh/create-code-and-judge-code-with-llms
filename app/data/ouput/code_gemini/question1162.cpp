/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string ataque, defesa;
    std::cin >> ataque >> defesa;

    if (ataque == defesa) {
        std::cout << "Empate\n";
        return 0;
    }

    if ((ataque == "Agua" && (defesa == "Fogo" || defesa == "Terra" || defesa == "Pedra")) ||
        (ataque == "Fogo" && (defesa == "Planta" || defesa == "Gelo")) ||
        (ataque == "Planta" && (defesa == "Agua" || defesa == "Terra")) ||
        (ataque == "Gelo" && (defesa == "Planta" || defesa == "Terra" || defesa == "Voador")) ||
        (ataque == "Terra" && (defesa == "Fogo" || defesa == "Eletrico" || defesa == "Pedra")) ||
        (ataque == "Eletrico" && (defesa == "Agua" || defesa == "Voador")) ||
        (ataque == "Voador" && (defesa == "Planta")) ||
        (ataque == "Pedra" && (defesa == "Fogo" || defesa == "Gelo" || defesa == "Voador"))) {
        std::cout << "Vantagem\n";
    } else {
        std::cout << "Desvantagem\n";
    }

    return 0;
}
