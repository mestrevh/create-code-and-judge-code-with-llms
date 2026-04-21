/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, z;
    if (!(cin >> x >> y >> z)) return 0;

    bool valid = true;
    if (y < 1 || y > 12) valid = false;
    if (z < 1) valid = false;

    int daysInMonth = 0;
    if (valid) {
        if (y == 2) {
            daysInMonth = 28;
        } else if (y == 4 || y == 6 || y == 9 || y == 11) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }
        if (x < 1 || x > daysInMonth) valid = false;
    }

    if (!valid) {
        cout << "Data invalida";
        return 0;
    }

    x++;
    if (y == 2 && x > 28) {
        x = 1; y = 3;
    } else if ((y == 4 || y == 6 || y == 9 || y == 11) && x > 30) {
        x = 1; y++;
    } else if (x > 31) {
        x = 1; y++;
    }

    if (y > 12) {
        y = 1;
        z++;
    }

    cout << x << "." << y << "." << z;
    return 0;
}