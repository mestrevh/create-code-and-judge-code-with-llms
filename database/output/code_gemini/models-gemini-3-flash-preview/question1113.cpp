/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Date Validation
 * Constraints: Year between 1900 and 2100 inclusive.
 * Rules: Gregorian calendar leap year rules.
 * Leap Year: (Year % 4 == 0 AND Year % 100 != 0) OR (Year % 400 == 0).
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, m, y;
    // Reading input: Day, Month, Year
    if (!(cin >> d >> m >> y)) return 0;

    bool is_valid = true;

    // Check year range as specified in the problem description
    if (y < 1900 || y > 2100) {
        is_valid = false;
    } 
    // Check month range
    else if (m < 1 || m > 12) {
        is_valid = false;
    } 
    else {
        int max_days;
        // Determine the number of days in the month
        if (m == 2) {
            // Leap year logic for February
            bool is_leap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
            max_days = is_leap ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            // April, June, September, November have 30 days
            max_days = 30;
        } else {
            // All other months have 31 days
            max_days = 31;
        }

        // Check if day is within valid range for that month/year
        if (d < 1 || d > max_days) {
            is_valid = false;
        }
    }

    // Final output based on validity
    if (is_valid) {
        cout << "valida" << endl;
    } else {
        cout << "invalida" << endl;
    }

    return 0;
}