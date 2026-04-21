/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int age;
    long long sum = 0;
    int count = 0;

    while (std::cin >> age && age >= 0) {
        sum += age;
        count++;
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        std::cout << std::fixed << std::setprecision(2) << average << "\n";
    }

    return 0;
}