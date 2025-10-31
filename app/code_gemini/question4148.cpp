/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

bool is_leap(long long year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, long long year) {
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

    long long d, m, y;
    long long n;
    char slash;

    std::cin >> d >> slash >> m >> slash >> y;
    std::cin >> n;

    d += n;

    while (d > days_in_month(m, y)) {
        d -= days_in_month(m, y);
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }

    std::cout << std::setw(2) << std::setfill('0') << d << "/"
              << std::setw(2) << std::setfill('0') << m << "/"
              << y << std::endl;

    return 0;
}
