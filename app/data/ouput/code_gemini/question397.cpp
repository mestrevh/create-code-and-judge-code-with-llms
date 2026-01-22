/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int guests_input;
    double total_extra_cost = 0.0;
    int total_people = 0;
    int graduates_count = 0;

    while (std::cin >> guests_input && guests_input >= 0) {
        graduates_count++;

        int actual_guests = guests_input;
        if (actual_guests > 25) {
            actual_guests = 25;
        }
        
        total_people += actual_guests;

        if (actual_guests > 15) {
            int extra_guests = actual_guests - 15;
            total_extra_cost += extra_guests * 42.0;
        }
    }

    total_people += graduates_count;

    std::cout << std::fixed << std::setprecision(2) << total_extra_cost << std::endl;
    std::cout << total_people << std::endl;

    return 0;
}
