/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string clima;
    std::string data;
    std::string mensagem;

    std::cin >> clima;
    std::cin >> data;
    std::cin.ignore();
    std::getline(std::cin, mensagem);

    int soma_ano = (data[6] - '0') + (data[7] - '0') + (data[8] - '0') + (data[9] - '0');
    int soma_dia_mes = (data[0] - '0') + (data[1] - '0') + (data[3] - '0') + (data[4] - '0');
    int chave = soma_ano - soma_dia_mes;
    chave = std::abs(chave);

    for (char &c : mensagem) {
        if (c != ' ') {
            c -= chave;
        }
    }

    if (clima == "ensolarado") {
        std::reverse(mensagem.begin(), mensagem.end());
        std::cout << mensagem << std::endl;
    } else if (clima == "chuvoso") {
        std::stringstream ss(mensagem);
        std::string palavra;
        std::string resultado_final = "";
        bool primeira_palavra = true;

        while (ss >> palavra) {
            if (!primeira_palavra) {
                resultado_final += " ";
            }

            if (palavra.length() % 2 == 0) {
                for (char &c : palavra) {
                    c++;
                }
            } else {
                for (char &c : palavra) {
                    c--;
                }
            }
            resultado_final += palavra;
            primeira_palavra = false;
        }
        std::cout << resultado_final << std::endl;
    } else {
        std::cout << "Mensagem codificada invalida, provavelmente mais uma tentativa dos aliens de nos enganar!" << std::endl;
    }

    return 0;
}
