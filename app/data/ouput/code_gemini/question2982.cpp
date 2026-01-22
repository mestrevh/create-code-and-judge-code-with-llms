/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n;
    std::cin >> n;

    int total_cents = static_cast<int>(n * 100.0 + 0.001);

    int notes[] = {10000, 5000, 2000, 1000, 500, 200};
    int coins[] = {100, 50, 25, 10, 5, 1};

    std::cout << std::fixed << std::setprecision(2);

    for (int note_value : notes) {
        int count = total_cents / note_value;
        if (count > 0) {
            std::cout << count << " nota(s) de R$ " << static_cast<double>(note_value) / 100.0 << "\n";
        }
        total_cents %= note_value;
    }

    for (int coin_value : coins) {
        int count = total_cents / coin_value;
        if (count > 0) {
            std::cout << count << " moeda(s) de R$ " << static_cast<double>(coin_value) / 100.0 << "\n";
        }
        total_cents %= coin_value;
    }

    return 0;
}
