/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

long long getTotalDays(int d, int m, int y) {
    long long total = 0;
    int prev_y = y - 1;
    total += 1LL * prev_y * 365;
    total += (prev_y / 4) - (prev_y / 100) + (prev_y / 400);

    static const int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < m; ++i) {
        total += monthDays[i];
        if (i == 2 && isLeap(y)) {
            total++;
        }
    }
    total += d;
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;

    if (!(cin >> d1 >> m1 >> y1)) return 0;
    if (!(cin >> d2 >> m2 >> y2)) return 0;

    long long days1 = getTotalDays(d1, m1, y1);
    long long days2 = getTotalDays(d2, m2, y2);

    long long diff = days2 - days1;
    cout << diff << endl;

    return 0;
}