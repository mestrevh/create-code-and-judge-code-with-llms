/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double salary;
    int extra_hours;

    if (!(std::cin >> salary >> extra_hours)) return 0;

    double hourly_rate = salary / 44.0;
    double extra_hour_value = hourly_rate * 1.10;
    double final_salary = salary + (extra_hour_value * extra_hours);

    std::cout << std::fixed << std::setprecision(2) << final_salary << std::endl;

    return 0;
}