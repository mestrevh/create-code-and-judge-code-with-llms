/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long start_year, end_year;
    if (!(cin >> start_year >> end_year)) {
        return 0;
    }

    bool found = false;
    for (long long y = start_year; y <= end_year; ++y) {
        bool is_leap = false;
        if (y % 400 == 0) {
            is_leap = true;
        } else if (y % 100 == 0) {
            is_leap = false;
        } else if (y % 4 == 0) {
            is_leap = true;
        }

        if (is_leap) {
            cout << y << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "-1\n";
    }

    return 0;
}