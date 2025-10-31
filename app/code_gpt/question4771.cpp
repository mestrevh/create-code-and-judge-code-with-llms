/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

int main() {
    int day, month, year, currentHour, currentMinute, addHour, addMinute;
    cin >> day >> month >> year >> currentHour >> currentMinute >> addHour >> addMinute;

    // Total minutes to add
    int totalMinutes = addHour * 60 + addMinute + currentHour * 60 + currentMinute;

    // Calculate new time
    int newHour = (totalMinutes / 60) % 24;
    int newMinute = totalMinutes % 60;
    int totalDays = totalMinutes / 1440;

    // Calculate new date
    for (int i = 0; i < totalDays; ++i) {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Output
    cout << setfill('0') << setw(2) << day << "\\" << setw(2) << month << "\\" << year << endl;
    cout << setw(2) << newHour << ":" << setw(2) << newMinute << endl;
    cout << "Falta " << totalDays << " dias até a data que o Esquisito falou" << endl;

    return 0;
}
