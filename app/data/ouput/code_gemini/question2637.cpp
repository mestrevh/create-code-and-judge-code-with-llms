/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> scores(6);
    bool negative_found = false;
    int total_sum = 0;

    for (int i = 0; i < 6; ++i) {
        std::cin >> scores[i];
    }

    for (int i = 1; i <= 6; ++i) {
        std::cout << "Digite pontuacao da partida " << i << ":\n";
    }

    for (int score : scores) {
        if (score < 0) {
            negative_found = true;
            break;
        }
        total_sum += score;
    }

    if (negative_found) {
        std::cout << "Valores negativos nao sao permitidos.\n";
    } else {
        std::cout << "Total de pontos: " << total_sum << ". ";
        if (total_sum >= 100) {
            std::cout << "O competidor esta classificado.\n";
        } else {
            std::cout << "O competidor esta desclassificado.\n";
        }
    }

    return 0;
}
