/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double donation;
    double total = 0.0;
    int count = 0;

    while (std::cin >> donation && donation >= 0) {
        total += donation;
        count++;
    }

    double average = 0.0;
    if (count > 0) {
        average = total / count;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << total << std::endl;
    std::cout << average << std::endl;

    return 0;
}
