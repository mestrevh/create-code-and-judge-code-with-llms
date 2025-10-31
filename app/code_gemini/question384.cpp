/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>

void to_upper(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nomeItem;
    double valorItem;
    
    double totalGasto = 0.0;
    double maiorValor = -1.0;
    std::string itemMaisCaro;

    while (std::cin >> nomeItem) {
        std::string tempNome = nomeItem;
        to_upper(tempNome);

        if (tempNome == "FIM") {
            break;
        }

        std::cin >> valorItem;
        totalGasto += valorItem;

        if (valorItem > maiorValor) {
            maiorValor = valorItem;
            itemMaisCaro = nomeItem;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << totalGasto << std::endl;
    
    to_upper(itemMaisCaro);
    std::cout << itemMaisCaro << std::endl;

    return 0;
}
