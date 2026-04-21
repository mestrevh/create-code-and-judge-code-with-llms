/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, m, y;
    if (!(cin >> d >> m >> y)) return 0;

    auto isLeap = [&](int year) {
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        return year % 4 == 0;
    };

    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool ok = true;

    if (y < 1900 || y > 2100) ok = false;
    if (m < 1 || m > 12) ok = false;
    else {
        int maxd = days[m];
        if (m == 2 && isLeap(y)) maxd = 29;
        if (d < 1 || d > maxd) ok = false;
    }

    cout << (ok ? "valida" : "invalida");
    return 0;
}