/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ambrosio_num;
    std::cin >> ambrosio_num;
    int lower_bound = 0;
    int upper_bound = 100;
    int guess;
    while (std::cin >> guess) {
        if (guess == ambrosio_num) {
            std::cout << "Voce bebe!\n";
            break;
        }
        if (guess < ambrosio_num) {
            if (guess > lower_bound) {
                lower_bound = guess;
            }
        } else { // guess > ambrosio_num
            if (guess < upper_bound) {
                upper_bound = guess;
            }
        }

        if (lower_bound == ambrosio_num - 1 && upper_bound == ambrosio_num + 1) {
            std::cout << "Ambrosio bebe!\n";
            break;
        }

        std::cout << "Escolha um numero entre " << lower_bound << " e " << upper_bound << "!\n";
    }
    return 0;
}
