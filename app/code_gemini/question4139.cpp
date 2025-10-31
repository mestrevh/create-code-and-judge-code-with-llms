/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, m;
    char colon;
    int minutes_to_add;

    std::cin >> h >> colon >> m;
    std::cin >> minutes_to_add;

    int total_initial_minutes = h * 60 + m;
    int total_final_minutes = total_initial_minutes + minutes_to_add;

    int final_h = (total_final_minutes / 60) % 24;
    int final_m = total_final_minutes % 60;

    std::cout << std::setw(2) << std::setfill('0') << final_h << ":"
              << std::setw(2) << std::setfill('0') << final_m << std::endl;

    return 0;
}
