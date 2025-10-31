/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int n;
    std::cin >> n;

    long long score_par = 0;
    long long score_impar = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::string word;
            std::cin >> word;

            if ((i + j) % 2 == 0) {
                for (size_t k = 0; k < word.length(); ++k) {
                    if (k % 2 == 0) {
                        score_par += static_cast<long long>(word[k]);
                    }
                }
            } else {
                for (size_t k = 0; k < word.length(); ++k) {
                    if (k % 2 != 0) {
                        score_impar += static_cast<long long>(word[k]);
                    }
                }
            }
        }
    }

    if (score_par > score_impar) {
        std::cout << "Os pares venceram com " << score_par << " pontos!\n";
    } else if (score_impar > score_par) {
        std::cout << "Os impares venceram com " << score_impar << " pontos!\n";
    } else {
        std::cout << "Tivemos um empate em " << score_par << " pontos!\n";
    }

    return 0;
}
