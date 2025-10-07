/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

bool is_leap(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

long long date_to_days(int d, int m, int y) {
    long long total_days = 0;
    
    for (int current_year = 1; current_year < y; ++current_year) {
        total_days += is_leap(current_year) ? 366 : 365;
    }

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int current_month = 1; current_month < m; ++current_month) {
        total_days += days_in_month[current_month];
        if (current_month == 2 && is_leap(y)) {
            total_days++;
        }
    }
    
    total_days += d;
    
    return total_days;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d1, m1, a1;
    int d2, m2, a2;

    std::cin >> d1 >> m1 >> a1;
    std::cin >> d2 >> m2 >> a2;

    long long days1 = date_to_days(d1, m1, a1);
    long long days2 = date_to_days(d2, m2, a2);

    std::cout << std::abs(days2 - days1) << std::endl;

    return 0;
}
