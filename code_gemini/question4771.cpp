/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d, m, y;
    int h, min;
    int add_h, add_min;

    std::cin >> d >> m >> y;
    std::cin >> h >> min;
    std::cin >> add_h >> add_min;

    long long total_minutes = static_cast<long long>(min) + add_min;
    int final_min = total_minutes % 60;
    long long carry_hours = total_minutes / 60;

    long long total_hours = static_cast<long long>(h) + add_h + carry_hours;
    int final_h = total_hours % 24;
    long long days_to_add = total_hours / 24;

    int final_d = d;
    int final_m = m;
    int final_y = y;

    for (long long i = 0; i < days_to_add; ++i) {
        final_d++;
        if (final_d > days_in_month(final_m, final_y)) {
            final_d = 1;
            final_m++;
            if (final_m > 12) {
                final_m = 1;
                final_y++;
            }
        }
    }

    std::cout << std::setw(2) << std::setfill('0') << final_d << "\\"
              << std::setw(2) << std::setfill('0') << final_m << "\\"
              << final_y << std::endl;

    std::cout << std::setw(2) << std::setfill('0') << final_h << ":"
              << std::setw(2) << std::setfill('0') << final_min << std::endl;

    std::cout << "Falta " << days_to_add << " dias até a data que o Esquisito falou" << std::endl;

    return 0;
}
