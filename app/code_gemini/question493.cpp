/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double temp;
    double min_temp = 0.0;
    double sum_neg_temps = 0.0;
    int count_neg_temps = 0;

    while (std::cin >> temp) {
        if (temp < min_temp) {
            min_temp = temp;
        }
        if (temp < 0) {
            sum_neg_temps += temp;
            count_neg_temps++;
        }
    }

    double avg_neg_temps = 0.0;
    if (count_neg_temps > 0) {
        avg_neg_temps = sum_neg_temps / count_neg_temps;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << min_temp << std::endl;
    std::cout << avg_neg_temps << std::endl;

    return 0;
}
