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

int daysBetween(int d1, int m1, int a1, int d2, int m2, int a2) {
    if (a1 > a2 || (a1 == a2 && m1 > m2) || (a1 == a2 && m1 == m2 && d1 > d2)) 
        swap(d1, d2), swap(m1, m2), swap(a1, a2);

    int days = 0;
    
    while (d1 != d2 || m1 != m2 || a1 != a2) {
        days++;
        d1++;
        if (d1 > daysInMonth(m1, a1)) {
            d1 = 1;
            m1++;
            if (m1 > 12) {
                m1 = 1;
                a1++;
            }
        }
    }
    
    return days;
}

int main() {
    int d1, m1, a1, d2, m2, a2;
    cin >> d1 >> m1 >> a1 >> d2 >> m2 >> a2;
    cout << daysBetween(d1, m1, a1, d2, m2, a2) << endl;
    return 0;
}
