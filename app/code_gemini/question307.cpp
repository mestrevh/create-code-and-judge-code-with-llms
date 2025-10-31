/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double n;
    std::cin >> n;

    int total_cents = static_cast<int>(n * 100 + 0.5);

    std::cout << "NOTAS:\n";

    int notes[] = {10000, 5000, 2000, 1000, 500, 200};
    double note_values[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00};

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < 6; ++i) {
        int count = total_cents / notes[i];
        std::cout << count << " nota(s) de R$ " << note_values[i] << "\n";
        total_cents %= notes[i];
    }

    std::cout << "MOEDAS:\n";

    int coins[] = {100, 50, 25, 10, 5, 1};
    double coin_values[] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};

    for (int i = 0; i < 6; ++i) {
        int count = total_cents / coins[i];
        std::cout << count << " moeda(s) de R$ " << coin_values[i] << "\n";
        total_cents %= coins[i];
    }

    return 0;
}
