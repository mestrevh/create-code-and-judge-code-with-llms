/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void solve() {
    int hh, mm, x;
    char colon;
    std::cin >> hh >> colon >> mm >> x;

    int total_minutes = hh * 60 + mm;
    const int minutes_in_day = 24 * 60;

    int sub_total_minutes = (total_minutes - x + minutes_in_day) % minutes_in_day;
    int sub_hh = sub_total_minutes / 60;
    int sub_mm = sub_total_minutes % 60;

    int add_total_minutes = (total_minutes + x) % minutes_in_day;
    int add_hh = add_total_minutes / 60;
    int add_mm = add_total_minutes % 60;

    std::cout << std::setw(2) << std::setfill('0') << sub_hh << ":"
              << std::setw(2) << std::setfill('0') << sub_mm << " "
              << std::setw(2) << std::setfill('0') << add_hh << ":"
              << std::setw(2) << std::setfill('0') << add_mm << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
