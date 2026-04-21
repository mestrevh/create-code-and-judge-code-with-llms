/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Checks if a given year is a leap year.
 * A leap year is divisible by 4 but not by 100, or it is divisible by 400.
 */
bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

/**
 * Calculates the total number of days from year 0 to the given date.
 */
long long total_days(int d, int m, int y) {
    long long prev_y = y - 1;
    // Days in full years before the current year, including leap days
    long long days = prev_y * 365 + prev_y / 4 - prev_y / 100 + prev_y / 400;

    // Days in months of the current year
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i < m; ++i) {
        days += months[i];
    }

    // Add an extra day if the current year is leap and we've passed February
    if (m > 2 && is_leap(y)) {
        days++;
    }

    // Add current days
    days += d;
    return days;
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;

    // Reading current date and wedding date
    if (!(cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2)) return 0;

    // Calculate the difference in days
    long long current_total = total_days(d1, m1, y1);
    long long wedding_total = total_days(d2, m2, y2);

    cout << (wedding_total - current_total) << endl;

    return 0;
}