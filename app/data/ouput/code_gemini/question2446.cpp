/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_leap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

long long date_to_days(int d, int m, int y) {
    long long total_days = 0;
    
    for (int i = 1; i < y; ++i) {
        if (is_leap(i)) {
            total_days += 366;
        } else {
            total_days += 365;
        }
    }

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1; i < m; ++i) {
        total_days += days_in_month[i];
        if (i == 2 && is_leap(y)) {
            total_days += 1;
        }
    }

    total_days += d;

    return total_days;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;

    std::cin >> d1 >> m1 >> y1;
    std::cin >> d2 >> m2 >> y2;

    long long total_days1 = date_to_days(d1, m1, y1);
    long long total_days2 = date_to_days(d2, m2, y2);

    std::cout << total_days2 - total_days1 << std::endl;

    return 0;
}
