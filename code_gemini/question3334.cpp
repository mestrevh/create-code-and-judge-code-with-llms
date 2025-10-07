/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

long long date_to_days(int d, int m, int y) {
    long long total_days = 0;
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1; i < y; ++i) {
        total_days += is_leap(i) ? 366 : 365;
    }

    for (int i = 1; i < m; ++i) {
        total_days += days_in_month[i];
        if (i == 2 && is_leap(y)) {
            total_days++;
        }
    }

    total_days += d;
    return total_days;
}

void days_to_date(long long total_days, int& d, int& m, int& y) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    y = 1;

    while (true) {
        int days_in_current_year = is_leap(y) ? 366 : 365;
        if (total_days <= days_in_current_year) {
            break;
        }
        total_days -= days_in_current_year;
        y++;
    }

    m = 1;
    while (true) {
        int current_month_days = days_in_month[m];
        if (m == 2 && is_leap(y)) {
            current_month_days++;
        }
        if (total_days <= current_month_days) {
            break;
        }
        total_days -= current_month_days;
        m++;
    }
    
    d = static_cast<int>(total_days);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;
    char slash;

    std::cin >> d1 >> slash >> m1 >> slash >> y1;
    std::cin >> d2 >> slash >> m2 >> slash >> y2;

    long long days1 = date_to_days(d1, m1, y1);
    long long days2 = date_to_days(d2, m2, y2);

    long long diff = days2 - days1;
    long long offset = diff / 2;

    long long midpoint_total_days = days1 + offset;

    int d_mid, m_mid, y_mid;
    days_to_date(midpoint_total_days, d_mid, m_mid, y_mid);

    std::cout << std::setfill('0') << std::setw(2) << d_mid << "/"
              << std::setfill('0') << std::setw(2) << m_mid << "/"
              << std::setfill('0') << std::setw(4) << y_mid << " ";

    if (diff % 2 == 0) {
        std::cout << "00:00\n";
    } else {
        std::cout << "12:00\n";
    }

    return 0;
}
