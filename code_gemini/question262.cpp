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

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
        std::cout << 0 << std::endl;
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<double> grades(n);
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        std::cin >> grades[i];
        sum += grades[i];
    }

    double average = sum / static_cast<double>(n);

    std::cout << std::fixed << std::setprecision(2) << average << std::endl;

    double upper_bound = average * 1.1;
    double lower_bound = average * 0.9;

    int above_count = 0;
    int below_count = 0;

    for (const double& grade : grades) {
        if (grade > upper_bound) {
            above_count++;
        }
        if (grade < lower_bound) {
            below_count++;
        }
    }

    std::cout << above_count << std::endl;
    std::cout << below_count << std::endl;

    return 0;
}
