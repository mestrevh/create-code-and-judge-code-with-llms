/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double num;
    double sum = 0.0;
    int count = 0;

    while (std::cin >> num) {
        if (num > 0) {
            long long int_part = static_cast<long long>(num);
            if (num == static_cast<double>(int_part) && int_part % 2 == 0) {
                sum += num;
                count++;
            }
        }
    }

    if (count == 0) {
        std::cout << -1 << std::endl;
    } else {
        double average = sum / count;
        std::cout << std::fixed << std::setprecision(2) << average << std::endl;
    }

    return 0;
}
