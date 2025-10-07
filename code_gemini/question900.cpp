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
    double number;
    for (int i = 0; i < 100; ++i) {
        std::cin >> number;
        sum += number;
    }
    double average = sum / 100.0;
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Media dos numeros: " << average << std::endl;
    return 0;
}
