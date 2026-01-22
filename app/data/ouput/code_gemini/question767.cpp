/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::sort(numbers.begin(), numbers.end());

    int n = numbers.size();

    std::cout << "Mediana = ";

    if (n % 2 != 0) {
        std::cout << numbers[n / 2] << std::endl;
    } else {
        double median = (static_cast<double>(numbers[n / 2 - 1]) + numbers[n / 2]) / 2.0;
        std::cout << std::fixed << std::setprecision(1) << median << std::endl;
    }

    return 0;
}
