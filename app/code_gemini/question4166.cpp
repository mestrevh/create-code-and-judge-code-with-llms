/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string inverter(std::string jogador) {
    std::reverse(jogador.begin(), jogador.end());
    return jogador;
}

void tratamento(char onde, char tipo, std::string jogador) {
    std::string resultado;

    if (onde == 'c') {
        resultado = inverter(jogador);
    } else { // onde == 'a'
        resultado = jogador;
    }

    if (tipo == '1') {
        if (!resultado.empty()) {
            char ultima_letra = resultado.back();
            for (int i = 0; i < 4; ++i) {
                resultado += ultima_letra;
            }
        }
    }

    std::cout << resultado << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char onde, tipo;
    std::string jogador;

    std::cin >> onde >> tipo;
    std::getline(std::cin >> std::ws, jogador);

    tratamento(onde, tipo, jogador);

    return 0;
}
