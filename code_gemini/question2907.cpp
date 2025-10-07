/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

long long dateToDays(int d, int m, int y) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long totalDays = 0;

    for (int currentYear = 1; currentYear < y; ++currentYear) {
        totalDays += isLeap(currentYear) ? 366 : 365;
    }

    for (int currentMonth = 1; currentMonth < m; ++currentMonth) {
        totalDays += daysInMonth[currentMonth];
        if (currentMonth == 2 && isLeap(y)) {
            totalDays++;
        }
    }

    totalDays += d;

    return totalDays;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;

    std::cin >> d1 >> m1 >> y1;
    std::cin >> d2 >> m2 >> y2;

    long long days1 = dateToDays(d1, m1, y1);
    long long days2 = dateToDays(d2, m2, y2);

    long long difference = days2 - days1;

    std::cout << difference << std::endl;

    return 0;
}
