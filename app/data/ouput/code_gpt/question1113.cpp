/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    int daysInMonth;
    switch(month) {
        case 2: daysInMonth = isLeapYear(year) ? 29 : 28; break;
        case 4: case 6: case 9: case 11: daysInMonth = 30; break;
        default: daysInMonth = 31; break;
    }
    return day >= 1 && day <= daysInMonth;
}

int main() {
    int day, month, year;
    cin >> day >> month >> year;
    cout << (isValidDate(day, month, year) ? "valida" : "invalida") << endl;
    return 0;
}
