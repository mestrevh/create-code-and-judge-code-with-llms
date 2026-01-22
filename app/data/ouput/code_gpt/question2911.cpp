/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int count = 0, sum = 0, x;
    while (std::cin >> x) {
        sum += x;
        count++;
    }
    double average = (count > 0) ? static_cast<double>(sum) / count : 0.0;
    std::cout << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << sum + 1 << std::endl;
    return 0;
}
