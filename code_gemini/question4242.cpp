/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string clima;
    std::string data_str;
    std::string mensagem;

    std::cin >> clima;
    std::cin >> data_str;
    std::cin.ignore();
    std::getline(std::cin, mensagem);

    if (clima != "ensolarado" && clima != "chuvoso") {
        std::cout << "Mensagem codificada invalida, provavelmente mais uma tentativa dos aliens de nos enganar!" << std::endl;
        return 0;
    }

    int soma_ano = (data_str[6] - '0') + (data_str[7] - '0') + (data_str[8] - '0') + (data_str[9] - '0');
    int soma_dia_mes = (data_str[0] - '0') + (data_str[1] - '0') + (data_str[3] - '0') + (data_str[4] - '0');
    int chave = std::abs(soma_ano - soma_dia_mes);

    for (char &c : mensagem) {
        if (c != ' ') {
            c -= chave;
        }
    }

    if (clima == "ensolarado") {
        std::reverse(mensagem.begin(), mensagem.end());
    } else {
        std::stringstream ss(mensagem);
        std::string palavra;
        std::string mensagem_final = "";
        bool primeiro = true;

        while (ss >> palavra) {
            if (!primeiro) {
                mensagem_final += " ";
            }
            if (palavra.length() % 2 == 0) {
                for (char &c : palavra) {
                    c += 1;
                }
            } else {
                for (char &c : palavra) {
                    c -= 1;
                }
            }
            mensagem_final += palavra;
            primeiro = false;
        }
        mensagem = mensagem_final;
    }

    std::cout << mensagem << std::endl;

    return 0;
}
