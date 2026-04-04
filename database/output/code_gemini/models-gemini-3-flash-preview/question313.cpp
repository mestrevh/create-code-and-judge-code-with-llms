/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int row_index;
    char operation;
    if (!(std::cin >> row_index >> operation)) return 0;

    double sum = 0.0;
    double current_value;

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            std::cin >> current_value;
            if (i == row_index) {
                sum += current_value;
            }
        }
    }

    if (operation == 'M') {
        sum /= 12.0;
    }

    std::cout << std::fixed << std::setprecision(1) << sum << "\n";

    return 0;
}