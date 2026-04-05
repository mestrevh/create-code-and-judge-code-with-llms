/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

/**
 * Funcao para determinar o periodo da historia baseado no ano numerico.
 * Periodos:
 * 1: anterior a 4000 aC (y < -3999)
 * 2: de 3999 aC ate 476 dC (-3999 <= y <= 476)
 * 3: de 477 dC ate 1789 dC (477 <= y <= 1789)
 * 4: apos 1790 dC (y >= 1790)
 */
int get_history_period(int year) {
    if (year < -3999) {
        return 1;
    } else if (year >= -3999 && year <= 476) {
        return 2;
    } else if (year >= 477 && year <= 1789) {
        return 3;
    } else {
        return 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_year = INT_MIN;
    bool found = false;

    for (int i = 0; i < 3; ++i) {
        int year_val;
        string era;
        if (!(cin >> year_val >> era)) break;

        int current_year;
        if (era == "aC") {
            current_year = -year_val;
        } else {
            current_year = year_val;
        }

        if (!found || current_year > max_year) {
            max_year = current_year;
            found = true;
        }
    }

    if (found) {
        cout << get_history_period(max_year) << endl;
    }

    return 0;
}