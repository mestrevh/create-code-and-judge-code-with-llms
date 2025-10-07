/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x, y;
    std::cin >> n >> x >> y;

    std::map<int, std::pair<int, int>> special_purchases;
    for (int i = 0; i < y; ++i) {
        int h, m, z;
        char colon;
        std::cin >> h >> colon >> m >> z;
        int time_in_minutes = h * 60 + m;
        int minutes_elapsed = time_in_minutes - (7 * 60);
        int customer_idx = minutes_elapsed / 3;
        special_purchases[customer_idx] = {z, time_in_minutes};
    }

    long long total_cans_sold = 0;

    for (int i = 1; i <= n; ++i) {
        int cans_bought = 0;
        int purchase_time = 0;

        auto it = special_purchases.find(i);
        if (it != special_purchases.end()) {
            cans_bought = it->second.first;
            purchase_time = it->second.second;
        } else if (x > 0 && i % x == 0) {
            cans_bought = 1;
            purchase_time = (7 * 60) + i * 3;
        }

        if (cans_bought > 0) {
            long long cans_before = total_cans_sold;
            total_cans_sold += cans_bought;

            if (cans_before < 50 && total_cans_sold >= 50) {
                int h_out = purchase_time / 60;
                int m_out = purchase_time % 60;

                std::cout << "Quem levou a cesta basica foi o " << i << "* cliente atendido por coragem, as "
                          << std::setfill('0') << std::setw(2) << h_out << ":" 
                          << std::setfill('0') << std::setw(2) << m_out << ". Que comprou "
                          << cans_bought << (cans_bought == 1 ? " lata." : " latas.") << std::endl;
                return 0;
            }
        }
    }

    long long needed = 50 - total_cans_sold;
    std::cout << "Ainda nao foram vendidas latas suficientes. Faltam " << needed << " latas." << std::endl;

    return 0;
}
