/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<std::string> gabarito;

    while (true) {
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> temp_gabarito;
        while (ss >> word) {
            temp_gabarito.push_back(word);
        }

        if (temp_gabarito.size() == n) {
            gabarito = temp_gabarito;
            break;
        } else {
            std::cout << "Gabarito de tamanho errado. Entre com o novo gabarito:\n";
        }
    }

    std::string line_resposta;
    while (std::getline(std::cin, line_resposta)) {
        if (line_resposta == "sair") {
            break;
        }

        std::stringstream ss(line_resposta);
        std::string word;
        std::vector<std::string> resposta;
        while (ss >> word) {
            resposta.push_back(word);
        }

        if (resposta.size() != n) {
            std::cout << "Tamanho da resposta diferente do tamanho do gabarito.\n";
            continue;
        }

        int acertos = 0;
        for (int i = 0; i < n; ++i) {
            if (gabarito[i] == resposta[i]) {
                acertos++;
            }
        }

        double percentual = (static_cast<double>(acertos) / n) * 100.0;
        
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Percentual de acertos: " << percentual << "\n";
    }

    return 0;
}
