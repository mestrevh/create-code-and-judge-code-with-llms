/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    double sum = 0.0;
    double grade;

    for (int i = 0; i < n; ++i) {
        std::cin >> grade;
        sum += grade;
    }

    double average = sum / n;

    std::cout << std::fixed << std::setprecision(15) << average << std::endl;

    return 0;
}
