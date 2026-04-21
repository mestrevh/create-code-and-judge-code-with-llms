/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d;
    int calls_count = 0;
    int minutes_sum = 0;
    int extra_minutes = 0;

    while (std::cin >> d && d != 0) {
        if (calls_count < 10 && minutes_sum < 40) {
            if (minutes_sum + d > 40) {
                extra_minutes += (minutes_sum + d) - 40;
            }
            minutes_sum += d;
            calls_count++;
        } else {
            extra_minutes += d;
        }
    }

    double total_cost = 10.00 + (extra_minutes * 0.20);
    std::cout << std::fixed << std::setprecision(2) << total_cost << std::endl;

    return 0;
}