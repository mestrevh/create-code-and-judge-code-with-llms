/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

long long dateToDays(int d, int m, int y) {
    long long total = d;
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < m; ++i) {
        total += months[i];
    }
    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {
        total++;
    }
    y--;
    total += 1LL * y * 365 + (y / 4) - (y / 100) + (y / 400);
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;

    if (!(cin >> d1 >> m1 >> y1)) return 0;
    if (!(cin >> d2 >> m2 >> y2)) return 0;

    long long days1 = dateToDays(d1, m1, y1);
    long long days2 = dateToDays(d2, m2, y2);

    cout << (days2 - days1) << endl;

    return 0;
}