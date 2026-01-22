/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int miguel_score = 0;
    int maria_rita_score = 0;
    int valid_rounds = 0;

    std::string miguel_choice, maria_rita_choice;

    while (valid_rounds < 5) {
        std::cin >> miguel_choice >> maria_rita_choice;

        std::transform(miguel_choice.begin(), miguel_choice.end(), miguel_choice.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        std::transform(maria_rita_choice.begin(), maria_rita_choice.end(), maria_rita_choice.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (miguel_choice == maria_rita_choice) {
            continue;
        }

        valid_rounds++;

        if ((miguel_choice == "pedra" && maria_rita_choice == "tesoura") ||
            (miguel_choice == "papel" && maria_rita_choice == "pedra") ||
            (miguel_choice == "tesoura" && maria_rita_choice == "papel")) {
            miguel_score++;
        } else {
            maria_rita_score++;
        }
    }

    if (miguel_score > maria_rita_score) {
        std::cout << "MARIA RITA" << std::endl;
    } else {
        std::cout << "MIGUEL" << std::endl;
    }

    return 0;
}
