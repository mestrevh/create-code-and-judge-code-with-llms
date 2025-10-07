/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total_nails_needed = 0;
    int current_nails;

    while (std::cin >> current_nails) {
        if (current_nails % 2 != 0) {
            break;
        }
        total_nails_needed += current_nails;
    }

    int boxes_to_buy = 0;
    if (total_nails_needed > 0) {
        boxes_to_buy = (total_nails_needed + 11) / 12;
    }

    double total_cost = boxes_to_buy * 7.89;
    int total_nails_bought = boxes_to_buy * 12;
    int leftover_nails = total_nails_bought - total_nails_needed;

    std::cout << std::fixed << std::setprecision(2) << total_cost << std::endl;
    std::cout << leftover_nails << std::endl;

    return 0;
}
