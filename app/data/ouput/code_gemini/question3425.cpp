/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cfloat>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    double min_val = DBL_MAX;
    double max_val = -DBL_MAX;
    double sum = 0.0;
    int even_count = 0;

    for (int i = 0; i < n; ++i) {
        double num;
        std::cin >> num;

        if (num < min_val) {
            min_val = num;
        }
        if (num > max_val) {
            max_val = num;
        }

        sum += num;

        // Check if the number is an integer before checking for evenness
        if (num == floor(num)) {
            int int_val = static_cast<int>(num);
            if (int_val % 2 == 0) {
                even_count++;
            }
        }
    }

    double average = sum / n;
    double even_percentage = (static_cast<double>(even_count) / n) * 100.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << min_val << "\n";
    std::cout << max_val << "\n";
    std::cout << even_percentage << "\n";
    std::cout << average << "\n";

    return 0;
}
