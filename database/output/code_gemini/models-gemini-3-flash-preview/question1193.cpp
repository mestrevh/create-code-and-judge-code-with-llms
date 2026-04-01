/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isLeap(long long y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

long long getDays(int d, int m, int y) {
    long long total = d;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (int i = 1; i < m; ++i) {
        total += daysInMonth[i];
        if (i == 2 && isLeap(y)) {
            total += 1;
        }
    }
    
    long long prev_y = y - 1;
    total += prev_y * 365 + (prev_y / 4) - (prev_y / 100) + (prev_y / 400);
    
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, m1, a1;
    int d2, m2, a2;

    if (!(cin >> d1 >> m1 >> a1 >> d2 >> m2 >> a2)) return 0;

    long long days1 = getDays(d1, m1, a1);
    long long days2 = getDays(d2, m2, a2);

    long long diff = days2 - days1;
    if (diff < 0) diff = -diff;

    cout << diff << endl;

    return 0;
}