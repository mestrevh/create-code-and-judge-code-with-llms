/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

int main() {
    int estoque[4];
    std::string venda;
    std::map<std::string, int> index = {{"Fenix", 0}, {"Dragao", 1}, {"Unicornio", 2}, {"Testralio", 3}};
    std::map<std::string, int> precoGaleao = {{"Fenix", 5}, {"Dragao", 1}, {"Unicornio", 2}, {"Testralio", 3}};
    std::map<std::string, int> precoSicle = {{"Fenix", 16}, {"Dragao", 2}, {"Unicornio", 10}, {"Testralio", 10}};
    std::map<std::string, int> precoNuque = {{"Fenix", 22}, {"Dragao", 28}, {"Unicornio", 12}, {"Testralio", 0}};

    for (int i = 0; i < 4; i++)
        std::cin >> estoque[i];

    int totalG = 0, totalS = 0, totalN = 0;

    while (std::cin >> venda && venda != "FIM") {
        int tipo = index[venda];
        if (estoque[tipo] > 0) {
            estoque[tipo]--;
            totalG += precoGaleao[venda];
            totalS += precoSicle[venda];
            totalN += precoNuque[venda];
        }
    }

    std::cout << "Fenix " << estoque[0] << std::endl;
    std::cout << "Dragao " << estoque[1] << std::endl;
    std::cout << "Unicornio " << estoque[2] << std::endl;
    std::cout << "Testralio " << estoque[3] << std::endl;
    std::cout << totalG << " " << totalS << " " << totalN << std::endl;

    return 0;
}
