/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::map<std::string, int> dias, locais;
    std::string dia, local;

    for (int i = 0; i < 11; ++i) {
        std::cin >> dia >> local;
        std::transform(dia.begin(), dia.end(), dia.begin(), ::toupper);
        std::transform(local.begin(), local.end(), local.begin(), ::toupper);
        dias[dia]++;
        locais[local]++;
    }

    std::string diaEscolhido = (dias["SEXTA"] > dias["DOMINGO"]) ? "SEXTA" : "DOMINGO";
    std::string localEscolhido = (locais["BAR"] > locais["PRAIA"]) ? "BAR" : "PRAIA";

    std::cout << diaEscolhido << std::endl << localEscolhido << std::endl;

    return 0;
}
