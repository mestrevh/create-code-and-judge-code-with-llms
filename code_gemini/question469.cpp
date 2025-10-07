/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    int reinaldo_wins = 0;
    int helena_wins = 0;
    int reinaldo_score = 0;
    int helena_score = 0;

    for (int i = 0; i < 5; ++i) {
        int r_roll, h_roll;
        std::cin >> r_roll >> h_roll;

        reinaldo_score += r_roll;
        helena_score += h_roll;

        if (r_roll > h_roll) {
            reinaldo_wins++;
        } else if (h_roll > r_roll) {
            helena_wins++;
        }
    }

    if (reinaldo_wins > helena_wins) {
        std::cout << "REINALDO" << std::endl;
    } else if (helena_wins > reinaldo_wins) {
        std::cout << "HELENA" << std::endl;
    } else {
        if (reinaldo_score > helena_score) {
            std::cout << "REINALDO" << std::endl;
        } else if (helena_score > reinaldo_score) {
            std::cout << "HELENA" << std::endl;
        } else {
            std::cout << "EMPATE" << std::endl;
        }
    }

    return 0;
}
