/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int day, month, year;
    cin >> day;
    cin >> month;
    cin >> year;

    if (year < 1900 || year > 2020) {
        cout << "Ano inexistente" << endl;
        return 0;
    }
    if (month < 1 || month > 12) {
        cout << "Mês inexistente" << endl;
        return 0;
    }
    if (day < 1) {
        cout << "Dia inexistente" << endl;
        return 0;
    }

    int maxDays;
    if (month == 2) {
        maxDays = isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    } else {
        maxDays = 31;
    }

    if (day > maxDays) {
        cout << "Esse dia não existe nesse mês" << endl;
    } else {
        cout << "Data Validada" << endl;
    }

    return 0;
}
