/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

bool is_leap(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

int get_days_in_month(int m, int y) {
    if (m == 2) return is_leap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, m, y;
    char s1, s2;
    
    if (!(cin >> d >> s1 >> m >> s2 >> y)) return 0;

    d += 30;

    while (d > get_days_in_month(m, y)) {
        d -= get_days_in_month(m, y);
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }

    cout << setfill('0') << setw(2) << d << "/"
         << setfill('0') << setw(2) << m << "/"
         << setfill('0') << setw(4) << y << endl;

    return 0;
}