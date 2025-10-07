/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>

int main() {
    std::map<int, std::pair<std::string, double>> cardapio = {
        {1, {"X-Burguer", 10.0}},
        {2, {"X-Tudo", 23.75}},
        {3, {"Hot-Dog", 12.5}},
        {4, {"X-Salada", 18.0}},
        {5, {"Batata Frita", 8.5}}
    };

    int codigo;
    while (std::cin >> codigo, codigo != 0) {
        if (cardapio.find(codigo) != cardapio.end()) {
            int quantidade;
            std::cout << "Você escolheu " << cardapio[codigo].first << std::endl;
            std::cin >> quantidade;
            double total = quantidade * cardapio[codigo].second;
            std::cout << "Sua conta é de R$" << std::fixed << std::setprecision(2) << total << std::endl;
        } else {
            std::cout << "Código inválido" << std::endl;
        }
    }
    return 0;
}
