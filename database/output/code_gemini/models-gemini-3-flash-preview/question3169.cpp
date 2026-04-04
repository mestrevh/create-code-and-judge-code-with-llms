/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double hours, hourly_rate;
    if (std::cin >> hours >> hourly_rate) {
        double salary = 0;
        if (hours > 180.0) {
            double normal_pay = 180.0 * hourly_rate;
            double extra_hours = hours - 180.0;
            double bonus_pay = extra_hours * (hourly_rate * 1.5);
            salary = normal_pay + bonus_pay;
        } else {
            salary = hours * hourly_rate;
        }
        std::cout << salary << "\n";
    }

    return 0;
}