/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string ingredientes;
    std::getline(std::cin, ingredientes);

    if (ingredientes.size() != 7) {
        std::cout << "Invalido\n...Mas pelo menos ganhou um chute\n";
        return 0;
    }

    char pao_inicio = ingredientes[0], pao_fim = ingredientes[6];
    if ((pao_inicio != '.' && pao_inicio != ':') || pao_inicio != pao_fim) {
        std::cout << "Invalido\n...Mas pelo menos ganhou um chute\n";
        return 0;
    }

    bool carne_adicionada = false;
    int extras = 0;

    for (int i = 1; i < 6; i++) {
        char i_char = ingredientes[i];
        if (i_char == 'b' || i_char == 'f' || i_char == 'p') {
            carne_adicionada = true;
        } else if (i_char == 'A' || i_char == 'T' || i_char == 'C' || i_char == 'R') {
            if (extras < 3) {
                extras++;
            } else {
                std::cout << "Invalido\n...Mas pelo menos ganhou um chute\n";
                return 0;
            }
        } else if (i_char == 'P') {
            continue;
        } else if (i_char != ' ' && i_char != 'D' && i_char != 'M' && i_char != 'E') {
            std::cout << "Invalido\n...Mas pelo menos ganhou um chute\n";
            return 0;
        }
    }

    if (!carne_adicionada) {
        std::cout << "Invalido\n...Mas pelo menos ganhou um chute\n";
        return 0;
    }

    std::cout << "Valido\n";
    return 0;
}
