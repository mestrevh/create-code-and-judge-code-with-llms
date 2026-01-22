/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int countDays(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 == y2 && m1 == m2)
        return d2 - d1;

    int days = 0;
    for (int y = y1; y < y2; ++y) {
        days += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < m2; ++m) {
        days -= daysInMonth(m, y2);
    }
    days -= daysInMonth(m1, y1) - d1;
    days += d2;

    return days;
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    cout << countDays(d1, m1, y1, d2, m2, y2) << endl;
    return 0;
}
