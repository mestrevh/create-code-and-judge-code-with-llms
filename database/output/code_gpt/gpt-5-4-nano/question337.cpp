/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    int d, m, y;
    char c1, c2;
    stringstream ss(s);
    ss >> d >> c1 >> m >> c2 >> y;

    tm t = {};
    t.tm_mday = d;
    t.tm_mon = m - 1;
    t.tm_year = y - 1900;
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;

    time_t tt = mktime(&t);
    tt += 30LL * 24 * 60 * 60;

    tm *res = localtime(&tt);

    int nd = res->tm_mday;
    int nm = res->tm_mon + 1;
    int ny = res->tm_year + 1900;

    cout << setw(2) << setfill('0') << nd << "/"
         << setw(2) << setfill('0') << nm << "/"
         << setw(4) << setfill('0') << ny << "\n";

    return 0;
}