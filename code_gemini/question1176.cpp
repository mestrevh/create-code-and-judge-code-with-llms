/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string ataque, defesa;
    std::cin >> ataque >> defesa;
    if (ataque == defesa) {
        std::cout << "Empate\n";
    } else if ((ataque == "Agua" && defesa == "Fogo") ||
               (ataque == "Fogo" && defesa == "Planta") ||
               (ataque == "Planta" && defesa == "Agua")) {
        std::cout << "Vantagem\n";
    } else {
        std::cout << "Desvantagem\n";
    }
    return 0;
}
