/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int initialDay, initialMonth, initialYear;
    int initialHour, initialMinute;
    int addedHours, addedMinutes;

    cin >> initialDay >> initialMonth >> initialYear;
    cin >> initialHour >> initialMinute;
    cin >> addedHours >> addedMinutes;

    int finalMinute = initialMinute + addedMinutes;
    int finalHour = initialHour + addedHours + finalMinute / 60;
    finalMinute %= 60;

    int finalDay = initialDay + finalHour / 24;
    finalHour %= 24;

    int finalMonth = initialMonth;
    int finalYear = initialYear;

    while (true) {
        int days = daysInMonth[finalMonth];
        if (finalMonth == 2 && isLeap(finalYear)) {
            days++;
        }

        if (finalDay <= days) {
            break;
        }

        finalDay -= days;
        finalMonth++;
        if (finalMonth > 12) {
            finalMonth = 1;
            finalYear++;
        }
    }

    cout << setfill('0') << setw(2) << finalDay << "\\" << setw(2) << finalMonth << "\\" << finalYear << endl;
    cout << setw(2) << finalHour << ":" << setw(2) << finalMinute << endl;

    int daysPassed = 0;
    int currentDay = initialDay;
    int currentMonth = initialMonth;
    int currentYear = initialYear;

    while (currentYear < finalYear || (currentYear == finalYear && currentMonth < finalMonth) || (currentYear == finalYear && currentMonth == finalMonth && currentDay < finalDay)) {
        daysPassed++;
        currentDay++;
        int days = daysInMonth[currentMonth];
        if (currentMonth == 2 && isLeap(currentYear)) {
            days++;
        }
        if (currentDay > days) {
            currentDay = 1;
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        }
    }

    cout << "Falta " << daysPassed << " dias até a data que o Esquisito falou" << endl;

    return 0;
}
