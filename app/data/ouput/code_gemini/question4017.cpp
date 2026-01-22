/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int y;
    std::cin >> y;

    int count_y = 0;
    double sum_avg = 0.0;
    int count_avg = 0;

    for (int i = 0; i < 20; ++i) {
        int num;
        std::cin >> num;

        if (num == -1) {
            break;
        }

        if (num == y) {
            count_y++;
        }

        if (num > 0 && (num < 15 || num > 20)) {
            sum_avg += num;
            count_avg++;
        }
    }

    std::cout << "O número " << y << " apareceu " << count_y << " vez(es)\n";

    if (count_avg > 0) {
        double media = sum_avg / count_avg;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "A média dos números foi de: " << media << "\n";
    } else {
        std::cout << "Sem valores para calcular a média\n";
    }

    return 0;
}
