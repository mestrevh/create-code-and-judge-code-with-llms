/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool is_leap(long long y) {
    if (y <= 0) return false;
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int m, long long y) {
    static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y)) return 29;
    return days[m];
}

long long date_to_days(int d, int m, long long y) {
    long long prev_y = y - 1;
    long long total = prev_y * 365LL + prev_y / 4 - prev_y / 100 + prev_y / 400;
    for (int i = 1; i < m; ++i) {
        total += days_in_month(i, y);
    }
    total += d;
    return total;
}

void days_to_date(long long total, int &d, int &m, long long &y) {
    long long low = 1, high = 10000000000LL;
    y = 1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (date_to_days(1, 1, mid) <= total) {
            y = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    total -= (date_to_days(1, 1, y) - 1);
    m = 1;
    while (true) {
        int dim = days_in_month(m, y);
        if (total <= (long long)dim) break;
        total -= (long long)dim;
        m++;
    }
    d = (int)total;
}

void parse_date(const string &s, int &d, int &m, long long &y) {
    size_t p1 = s.find('/');
    size_t p2 = s.find('/', p1 + 1);
    d = stoi(s.substr(0, p1));
    m = stoi(s.substr(p1 + 1, p2 - p1 - 1));
    y = stoll(s.substr(p2 + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    while (cin >> s1 >> s2) {
        int d1, m1, d2, m2;
        long long y1, y2;
        
        parse_date(s1, d1, m1, y1);
        parse_date(s2, d2, m2, y2);

        long long D1 = date_to_days(d1, m1, y1);
        long long D2 = date_to_days(d2, m2, y2);

        long long diff = D2 - D1;
        long long mid_days = D1 + diff / 2;

        int rd, rm;
        long long ry;
        days_to_date(mid_days, rd, rm, ry);

        cout << setfill('0') << setw(2) << rd << "/"
             << setw(2) << rm << "/"
             << setw(4) << ry << " "
             << (diff % 2 == 0 ? "00:00" : "12:00") << "\n";
    }

    return 0;
}