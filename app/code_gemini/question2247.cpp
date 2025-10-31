/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

long long getTotalDays(int d, int m, int y) {
    long long totalDays = 0;

    for (int i = 1; i < y; ++i) {
        if (isLeap(i)) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 1; i < m; ++i) {
        totalDays += daysInMonth[i];
        if (i == 2 && isLeap(y)) {
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
    std::cin >> d1 >> m1 >> y1;

    int d2, m2, y2;
    std::cin >> d2 >> m2 >> y2;

    long long totalDays1 = getTotalDays(d1, m1, y1);
    long long totalDays2 = getTotalDays(d2, m2, y2);

    std::cout << totalDays2 - totalDays1 << std::endl;

    return 0;
}
