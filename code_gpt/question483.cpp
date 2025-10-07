/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string voto;
    int sim = 0, nao = 0, nulo = 0;

    while (true) {
        std::getline(std::cin, voto);
        std::transform(voto.begin(), voto.end(), voto.begin(), ::tolower);
        
        if (voto == "encerrar") break;

        if (voto == "sim") sim++;
        else if (voto == "nao") nao++;
        else if (voto == "nulo") nulo++;
    }

    if (sim > (nao + nulo)) std::cout << "COM FOGOS\n";
    else std::cout << "SEM FOGOS\n";

    return 0;
}
