/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>
#include <iomanip>

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int day, month, year;
    
    if (scanf("%d/%d/%d", &day, &month, &year) != 3) {
        return 1;
    }

    day += 30;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (true) {
        int currentMonthDays = daysInMonth[month];
        if (month == 2 && isLeap(year)) {
            currentMonthDays = 29;
        }

        if (day <= currentMonthDays) {
            break;
        }

        day -= currentMonthDays;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }

    printf("%02d/%02d/%04d\n", day, month, year);

    return 0;
}
