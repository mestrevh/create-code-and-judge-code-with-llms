/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

static int daysInMonth(int m, int y) {
    static int dim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) return dim[m] + (isLeap(y) ? 1 : 0);
    return dim[m];
}

static long long toSerial(int d, int m, int y) {
    long long days = 0;
    for (int year = 1; year < y; ++year) days += isLeap(year) ? 366 : 365;
    for (int month = 1; month < m; ++month) days += daysInMonth(month, y);
    days += d;
    return days;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int D1, M1, A1, D2, M2, A2;
    if (!(cin >> D1 >> M1 >> A1 >> D2 >> M2 >> A2)) return 0;

    long long s1 = toSerial(D1, M1, A1);
    long long s2 = toSerial(D2, M2, A2);

    cout << llabs(s2 - s1);
    return 0;
}