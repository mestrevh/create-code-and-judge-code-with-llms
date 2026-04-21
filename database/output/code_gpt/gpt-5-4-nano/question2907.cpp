/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

int daysInMonth(int m, int y) {
    static int dm[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) return dm[m] + (isLeap(y) ? 1 : 0);
    return dm[m];
}

long long daysFromEpoch(int d, int m, int y) {
    long long days = 0;
    for (int year = 1970; year < y; year++) days += isLeap(year) ? 366 : 365;
    for (int month = 1; month < m; month++) days += daysInMonth(month, y);
    days += (d - 1);
    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d1, m1, y1, d2, m2, y2;
    if (!(cin >> d1 >> m1 >> y1)) return 0;
    if (!(cin >> d2 >> m2 >> y2)) return 0;

    long long t1 = daysFromEpoch(d1, m1, y1);
    long long t2 = daysFromEpoch(d2, m2, y2);

    cout << (t2 - t1) << "\n";
    return 0;
}