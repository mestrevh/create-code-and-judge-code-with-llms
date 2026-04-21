/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLeap(long long y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

static int daysInMonth(long long y, int m) {
    static int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2) return mdays[m] + (isLeap(y) ? 1 : 0);
    return mdays[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long addDays;
    if (!(cin >> s)) return 0;
    if (!(cin >> addDays)) return 0;

    int d = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));
    long long y = stoll(s.substr(6,4));

    while (addDays > 0) {
        int dim = daysInMonth(y, m);
        long long remaining = dim - d;
        if (addDays <= remaining) {
            d += (int)addDays;
            addDays = 0;
        } else {
            addDays -= (remaining + 1);
            d = 1;
            m++;
            if (m == 13) {
                m = 1;
                y++;
            }
        }
    }

    while (addDays < 0) {
        if (d + addDays >= 1) {
            d += (int)addDays;
            addDays = 0;
        } else {
            addDays += d;
            m--;
            if (m == 0) {
                m = 12;
                y--;
            }
            d = daysInMonth(y, m);
        }
    }

    cout << setfill('0') << setw(2) << d << "/" << setw(2) << m << "/" << y << "\n";
    return 0;
}