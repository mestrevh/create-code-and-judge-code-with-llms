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

    int n;
    std::cin >> n;

    int kyara_score = 0;
    int vinicius_score = 0;

    for (int i = 0; i < n; ++i) {
        std::string kyara_move, vinicius_move;
        std::cin >> kyara_move >> vinicius_move;

        std::transform(kyara_move.begin(), kyara_move.end(), kyara_move.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        std::transform(vinicius_move.begin(), vinicius_move.end(), vinicius_move.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        bool kyara_valid = (kyara_move == "pedra" || kyara_move == "papel" || kyara_move == "tesoura");
        bool vinicius_valid = (vinicius_move == "pedra" || vinicius_move == "papel" || vinicius_move == "tesoura");

        if (!kyara_valid || !vinicius_valid) {
            continue;
        }

        if (kyara_move == vinicius_move) {
            continue;
        }

        if ((kyara_move == "pedra" && vinicius_move == "tesoura") ||
            (kyara_move == "tesoura" && vinicius_move == "papel") ||
            (kyara_move == "papel" && vinicius_move == "pedra")) {
            kyara_score++;
        } else {
            vinicius_score++;
        }
    }

    if (kyara_score > vinicius_score) {
        std::cout << "VINICIUS VAI LAVAR A LOUÇA!\n";
    } else if (vinicius_score > kyara_score) {
        std::cout << "KYARA VAI LAVAR A LOUÇA!\n";
    } else {
        std::cout << "OS DOIS VÃO LAVAR A LOUÇA JUNTOS!\n";
    }

    return 0;
}
