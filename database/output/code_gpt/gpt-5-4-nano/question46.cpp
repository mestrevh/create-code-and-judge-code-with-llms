/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long daysFromCivil(int y, int m, int d) {
    y -= m <= 2;
    const int era = (y >= 0 ? y : y - 399) / 400;
    const unsigned yoe = (unsigned)(y - era * 400);
    const unsigned doy = (153u * (m + (m > 2 ? -3 : 9)) + 2u) / 5u + (unsigned)(d - 1);
    const unsigned doe = yoe * 365u + doy;
    return (long long)era * 146097LL + (long long)doe;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    if (!getline(cin, s1)) return 0;
    while (s1.size() && isspace((unsigned char)s1.back())) s1.pop_back();
    if (!getline(cin, s2)) return 0;
    while (s2.size() && isspace((unsigned char)s2.back())) s2.pop_back();

    auto parseDate = [](const string& s) {
        int day = 0, month = 0, year = 0;
        size_t p1 = s.find('/');
        size_t p2 = s.find('/', p1 + 1);
        day = stoi(s.substr(0, p1));
        month = stoi(s.substr(p1 + 1, p2 - p1 - 1));
        year = stoi(s.substr(p2 + 1));
        return array<int,3>{year, month, day};
    };

    auto [y1, m1, d1] = parseDate(s1);
    auto [y2, m2, d2] = parseDate(s2);

    long long t1 = daysFromCivil(y1, m1, d1);
    long long t2 = daysFromCivil(y2, m2, d2);

    cout << llabs(t2 - t1) << "\n";
    return 0;
}