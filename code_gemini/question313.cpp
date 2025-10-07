/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L;
    char T;
    double M[12][12];
    double sum = 0.0;

    std::cin >> L;
    std::cin >> T;

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cin >> M[i][j];
        }
    }

    for (int j = 0; j < 12; ++j) {
        sum += M[L][j];
    }

    if (T == 'S') {
        std::cout << std::fixed << std::setprecision(1) << sum << std::endl;
    } else if (T == 'M') {
        std::cout << std::fixed << std::setprecision(1) << sum / 12.0 << std::endl;
    }

    return 0;
}
