/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double sum = 0.0;
    int count = 0;
    int number;

    while (std::cin >> number) {
        sum += number;
        count++;
    }

    if (count > 0) {
        double media = sum / count;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Media = " << media << std::endl;
    }

    return 0;
}
