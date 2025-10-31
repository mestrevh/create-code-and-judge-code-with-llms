/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(2);

    char car_type;
    int target_year;

    while (std::cin >> car_type >> target_year) {
        if (target_year <= 2005 || (car_type != 'S' && car_type != 'P' && car_type != 'G')) {
            std::cout << "Entrada inválida" << std::endl;
        } else {
            double trans[3][3] = {
                {0.5, 0.25, 0.25},
                {0.0, 0.0, 1.0},
                {1.0, 0.0, 0.0}
            };

            double prob[3] = {1.0, 0.0, 0.0};

            for (int year = 2006; year <= target_year; ++year) {
                double next_prob[3];
                next_prob[0] = prob[0] * trans[0][0] + prob[1] * trans[1][0] + prob[2] * trans[2][0];
                next_prob[1] = prob[0] * trans[0][1] + prob[1] * trans[1][1] + prob[2] * trans[2][1];
                next_prob[2] = prob[0] * trans[0][2] + prob[1] * trans[1][2] + prob[2] * trans[2][2];
                prob[0] = next_prob[0];
                prob[1] = next_prob[1];
                prob[2] = next_prob[2];
            }

            if (car_type == 'S') {
                std::cout << "Probabilidade de ter um Sedan em " << target_year << ": " << prob[0] * 100.0 << "%" << std::endl;
            } else if (car_type == 'P') {
                std::cout << "Probabilidade de ter um Palio em " << target_year << ": " << prob[1] * 100.0 << "%" << std::endl;
            } else {
                std::cout << "Probabilidade de ter um Gol em " << target_year << ": " << prob[2] * 100.0 << "%" << std::endl;
            }
        }
    }

    return 0;
}
